// movebook.c

inherit ITEM;

void create()
{
    set_name("��Ƥ�ؾ�", ({ "mystery picture","picture" }));
    set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
            "һ�������Զ�Ļ������Ƶ�ֽ����ϡ���Կ������ö���Щ���������\n");
        set("value", 1);
		set("material", "paper");
		set("skill", ([
            "name":         "wolf-curse", 
            "exp_required": 200000,              
			"sen_cost":		20,				
			"difficulty":	20,		
            "max_skill":    20      
		]) );
	}
	::init_item();
}
