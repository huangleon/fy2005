// book.c

inherit ITEM;

void create()
{
	set_name( "̫��ȭ����ͼ", ({ "taiji-book", "book" }));
	set_weight(100);
	set("unit", "��");
	set("long", "�����䵱��̫��ȭ����������ͼ��\n");
	set("value", 1000);
	set("skill", ([
	    "name":                 "taiji",
	    "exp_required": 5000,                
	    "sen_cost":             40,     
	    "difficulty":   30,            
	    "max_skill":    20           
	]) );
	::init_item();
}
