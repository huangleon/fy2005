#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(WHT"��������" NOR, ({ "yue-script" }));
	set_weight(20);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����������µı����ֲᣬ���ľ����о����̡������ñ��ľ���Ҫ����\n");
		set("material", "paper");
		set("skill", ([
			"name": 	"strategy",		
			"exp_required":	50000,				
			"sen_cost":	30,			
			"difficulty":	30,			
			"max_skill":	80		
			]) );
		}
}
