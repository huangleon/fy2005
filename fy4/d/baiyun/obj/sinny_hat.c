#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name(HIY"ͨ��ˮ��"NOR, ({ "hat" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�ʵ۵����ڣ���ϸ�緢˿�Ľ�˿��֯���ɵģ��������������Ķ���Ϸˮ��\n");
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("value", 100);
		set("thief_obj", 1);
	}
	::init_head();
}

/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
