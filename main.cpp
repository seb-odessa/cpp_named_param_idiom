#include <iostream>
#include <string>

class Props
{
    friend class Control;
    int32_t m_id;
    std::string m_name;

public:
    Props() : m_id(0) {}
    Props &id(const int32_t id)
    {
        m_id = id;
        return *this;
    }
    Props &name(std::string const &name)
    {
        m_name = name;
        return *this;
    }
};

class Control
{
public:
    Control(Props const &p) : m_props(p) {}

    const int32_t id() const { return m_props.m_id; }

    const std::string &name() const { return m_props.m_name; }

private:
    Props m_props;
};

int main(int, char **)
{
    const auto ctrl = Control{Props{}.id(42).name("Button")};

    std::cout << "control: " << ctrl.id() << "-" << ctrl.name() << "\n";
}
