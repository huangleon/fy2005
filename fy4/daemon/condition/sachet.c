#include <ansi.h>
#include <condition.h>


int update_condition(object me, int duration)
{
        int i;

        string *num = ({
        "$N"HIM"��������һ�㵭��ǳǳ�ĺ�ɫ���������������Σ����⶯�ˡ�",
        "$N"HIM"�������죬��Ŀ��ֱ��Ҫ�γ�ˮ�������ҹ������ˣ������ѽ���",
        "$N"HIM"�����鲻ʤ��������΢΢���ظ�һ��һ�������������޹���",
        "$N"HIM"ҧ���´���˫�ְ�סС������������һ��ϸϸ�ĺ��顣",
        "$N"HIM"ü�Ľ��壬��ɫ�κ죬�ݳ�һ�����������������ż����ʹ�ࡣ",
        });

        string *num2 = ({
        "$N"HIM"�ս�˫ȭ����Բ��һ˫�۾�������ͨ�죬�͵ʹ�����",
        "$N"HIM"�����˺�Ȼ���������Ͼ���Ҫɢ����������",
        "$N"HIM"˫Ŀ��죬��ݺݵ�Ѳ�����ڳ���ÿ���ˣ�����ȥ��˵�����ķ�����",
        "$N"HIM"���������۾�����ں������·𴭲�������",
        "$N"HIM"����һ��Ұ�ް�ĵ���������߹���һ����һ�������ˮ�顣",
        });

        if (me->query("gender") == "Ů��")
                message_vision(HIM+num[random(sizeof(num))]+"\n"NOR,me);
        else
                message_vision(HIM+num2[random(sizeof(num2))]+"\n"NOR,me);

        duration --;
        if( duration < 1 ) return 0;
        	
        me->apply_condition("sachet", duration);
        return 1;
}

int condition_type()
{
// in condition.h
/*

#define NO_CURE                 100
#define SPECIFIC_POISON         30
#define MID_POISON              20
#define LOW_POISON              10
#define GENERIC                 0

*/
        return NO_CURE;
}

string cont_name()	{ return "����һ��ɢ"; }

int shown_stat()	{ return 1;}	