// book.c

inherit ITEM;

void create()
{
        set_name( "ռ������", ({ "book" }));
        set_weight(100);
        set("value", 10000);
        set("unit", "��");
        set("long", "����һ������ռ��ѧ���鼮��\n");
        set("skill", ([
                "name":                 "foreknowledge",
                "exp_required": 	0,                
                "sen_cost":             5,     
                "difficulty":   	30,            
                "max_skill":    	49
                                            
        ]) );
	::init_item();
}
