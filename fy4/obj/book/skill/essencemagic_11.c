
#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("����ս��", ({ "zhanpao" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",	"һ��ɫ�����޵�ս�ۡ�\n");
		set("value", 2);
		set("material", "cloth");
		set("skill", ([
			"name": 	"essencemagic",	
			"exp_required":	0,				
			"sen_cost":	2,				
			"difficulty":	20,		
			"max_skill":	10		
		]) );
		set("armor_prop/armor",10);
	}
	::init_cloth();
}
