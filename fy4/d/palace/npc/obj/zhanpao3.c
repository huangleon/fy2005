
#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("ʥ������", ({ "zhanpao" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"һ��ɫ�����޵����硣\n");
		set("value", 2);
		set("material", "cloth");
		set("skill", ([
			"name": 	"qidaoforce",	
			"exp_required":	0,				
			"sen_cost":	20,				
			"difficulty":	20,		
			"max_skill":	10		
		]) );
		set("armor_prop/armor",10);
		}
	::init_cloth();
}
