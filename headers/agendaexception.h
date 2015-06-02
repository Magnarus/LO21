#ifndef AGENDAEXCEPTION_H
#define AGENDAEXCEPTION_H
class AgendaException{
public:
    AgendaException(const QString& message):info(message){}
    QString getInfo() const { return info; }
private:
    QString info;
};
#endif // AGENDAEXCEPTION_H
