#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY"����"NOR, ({ "jade seal","seal" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����ʥ�ϵ�����������С׭���ţ��������죬����������\n");
		set("unit", "��");
		set("material", "cloth");
		set("value", 100);
		set("thief_obj", 1);
	}
}

/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
