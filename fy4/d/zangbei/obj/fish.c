inherit ITEM;
inherit F_FOOD;

void create()
{
	int i;
	string *names = ({ "����", "����", "������" });
	i = random(3);
    	set_name(names[i], ({ "fish" }) );
    	set_weight(500);
    	if( clonep() )
	    set_default_object(__FILE__);
    	else {
	        set("long", "����һ���ոյ����������㡣\n");
	        set("unit", "��");
	        set("value", 150);
	        set("food_remaining", 3);
	        set("food_supply", 10);
	    	set("marks/catfood", 1);
    	}
    	::init_item();
}

void init() {
	::init();
	call_out("badfish", 120);
}

void badfish() {
	set("long", "�Ѿ��������ʵ���ɢ����һ���ȳ�ζ��\n");
	set("name", "ɢ�����ȳ�ζ����");
	set("marks/catfood", 0);
	set("value", 0);
}

