
#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("��ȸս��", ({ "zhanyi" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"һ��ɫ�����޵�ս�¡�\n");
		set("value", 2);
		set("material", "cloth");
		set("skill", ([
			"name": 	"buddhism",	
			"exp_required":	5000,				
			"sen_cost":	2,				
			"difficulty":	20,		
			"max_skill":	50		
		]) );
		set("armor_prop/armor",10);
	}
	::init_cloth();
}
