
inherit ITEM;

void create()
{
	set_name("���ϵ�÷֦", ({ "meizhi"}));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
                        "һ�������߳���÷֦���ƺ��Ǳ�ʲô�������ϡ�Ȼ���Ͽڴ��ܳ��� 
������ƽ�������÷֦�������ġ�÷֦��ī�۵�㣬�ƺ�������ī�������˽��Ƶ�����ȥ����\n");
                
		set("value", 700);
		set("material", "paper");
		set("no_sell",1);
		set("no_get",1);
		set("no_drop",1); 
		set("skill", ([
			"name": 	"13-sword",	
			"exp_required":	2000000,		
			"sen_cost":	10,	
			"difficulty":	5,	
			"max_skill":	99,
			"liter_level":  50,
		]) );
	}
		::init_item();
}

 /*
void create()
{
	set_name("���ϵ�÷֦", ({ "meizhi"}));
	set_weight(100);
	set("unit", "��");
	set("no_sell",1);
	set("no_give",1);
	set("no_drop",1);
	set("value", 100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long",
                        "һ�������߳���÷֦���ƺ��Ǳ�ʲô�������ϡ�Ȼ���Ͽڴ��ܳ��� 
������ƽ�������÷֦�������ġ�÷֦��ī�۵�㣬�ƺ�������ī�������˽��Ƶ�����ȥ����\n");
                
		set("skill", ([
			"name":       "qingfeng-sword",	
			"exp_required":	2000000,		
			"sen_cost":	50,	
			"difficulty":	90,	
			"max_skill":	120,
			"liter_level":  50,
		]) );
	}

}
   */