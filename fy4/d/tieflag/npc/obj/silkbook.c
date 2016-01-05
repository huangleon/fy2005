// book.c
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name( "����", ({ "silk book", "book" }));
    set_weight(100);
    set("unit", "��");
    set("long", "����������֮����������Ѫд�ɵ�һ��С���ӡ���read��\n");
    set("value", 1);
    set("skill", ([
        "name":                 "jiayiforce",
        "exp_required": 5000,                
        "sen_cost":             40,     
        "difficulty":   30,            
        "max_skill":    70           
    ]) );
    ::init_item();
} 

void init()
{
        add_action("do_read", "read");
} 

int do_read()
{
	object me;
	me=this_player();
	message_vision(YEL "\n $n��������ĵ�һҳ��\n" NOR, this_object(), me);
	write(RED"    �������֡���ɷ����ħ���Ŷ�ʮ�˿�Ϊ�������������˵�����������\n"NOR);
	write(RED"��ŭ�����ԣ����ض��ꡣ\n"NOR);
	write(RED"    ֱ�������ơ�����λ���˳�����������ɽ����ͥ����ԡ�̫����������\n"NOR);
	write(RED"���ء��������ۣ���С��ʮս�����������񽣣�ɱ�����֡���ɷ����ħ��\n"NOR);
	write(RED"�Ŷ�ʮ�˿ܣ��Դ���ʮһ��֮��Ѫ��Ⱦ��һ����졣\n"NOR);
	write(RED"�����˸ж�ͼ��������������Ⱥ����ס�\n"NOR);
	write(RED"    �����ơ������洴���Ҵ����ţ��Ե������ţ��Ե������棬�Ե�����ˡ�\n"NOR);
	write(RED"   ��Ը�������ˣ������ҡ�Т���ʡ������š��塢�͡�ƽ���֣�������\n"NOR);
	write(RED"�棬������ǿ���������塣��\n"NOR);
	write(RED"    �Ա�һ���ּ���д���ǣ��������ŵڶ�������������ī�����㹧¼����\n"NOR);
	write("\n");
	me->set_temp("mark/silkbook",1);
	return 1;
}
