#ifndef _ELYIR_LOGGER_
#define _ELYIR_LOGGER_

const uint8_t LOG_LEVEL_NONE = 0;
const uint8_t LOG_LEVEL_INFO = 1;
const uint8_t LOG_LEVEL_DEBUG = 2;
const uint8_t LOG_LEVEL_WARNING = 3;
const uint8_t LOG_LEVEL_ERROR = 4;
const uint8_t LOG_LEVEL_ALL = 5;




class Logger {
    public:
        Logger(){};
        Logger(String tag) { this->setTag(tag); }
        Logger(String tag, int level)
        {
            this->setLevel(level);
            this->setTag(tag);
        }

        template<class T>
        void log(T message){
            if (this->level >= LOG_LEVEL_INFO)
            {
                _show("INFO", this->tag, message);
                log_in_progress = true;
            } else
            {
                log_in_progress = false;
            }
            
        }
        template<class T>
        void logln(T message){
            if (this->level >= LOG_LEVEL_INFO)
            {
                _showln("INFO", this->tag, message);
                log_in_progress = true;
            }
            else
            {
                log_in_progress = false;
            }
        }
        
        template<class T>
        void info(T message){
            this->log(message);
        }
        template<class T>
        void infoln(T message){
            this->logln(message);
        }
        
        template<class T>
        void debug(T message)
        {
            if (this->level >= LOG_LEVEL_DEBUG)
            {
                _show("DEBUG", this->tag, message);
                log_in_progress = true;
            }
            else
            {
                log_in_progress = false;
            }
        }
        template<class T>
        void debugln(T message){
            this->debug(message);
            this->appendln("");
        }
        
        template<class T>
        void warn(T message){
            if (this->level >= LOG_LEVEL_WARNING)
            {
                _show("WARNING", this->tag, message);
                log_in_progress = true;
            }
            else
            {
                log_in_progress = false;
            }
        }
        template<class T>
        void warnln(T message){
            this->warn(message);
            this->appendln("");
        }
        
        template<class T>
        void error(T message){
            if (this->level >= LOG_LEVEL_ERROR)
            {
                _show("ERROR", this->tag, message);
                log_in_progress = true;
            }
            else
            {
                log_in_progress = false;
            }
        }
        template<class T>
        void errorln(T message){
            this->error(message);
            this->appendln("");
        }

        template<class T>
        void append(T message){
            if (log_in_progress)
                Serial.print(message);
        }
        template<class T>
        void appendln(T message){
            if (log_in_progress)
            Serial.println(message);
        }

        void setLevel(int level){
            this->level = level;
        }
        void setTag(String tag){
            this->tag = tag;
        }

    private:
        int level = 0;
        bool log_in_progress = 0;
        String tag = "";
        template <class T>
        void _show(String type, String tag, T message)
        {
            Serial.print(type);
            Serial.print("  [ ");
            Serial.print(tag);
            Serial.print(" ]  ");
            Serial.print(message);
        }
        template <class T>
        void _showln(String type, String tag, T message)
        {
            _show(type, tag, message);
            Serial.println();
        }
};

#endif