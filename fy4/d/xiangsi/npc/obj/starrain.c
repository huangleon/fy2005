// annie 07.2003
// dancing_faery@hotmail.com

inherit ITEM;

void create()
{
	set_name("�Ǻ��ݺ�", ({ "sky map","map" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"һ����ͼ�������������Ƶ����Ǻ�����֮·��\n��ͼ�����½Ǳ�ע��һ��СС�ģ�꿣��֡�\n");
		set("value", 0);
		set("material", "paper");
		set("skill", ([
			"name":	"starrain",		
			"sen_cost":	10,
			"difficulty":	20,	
			"max_skill":	50,
		]) );
	}
	::init_item();
}


