inherit ITEM;

void create()
{
	set_name("С����", ({"book", "puti steps"}) );
	set_weight(20);
	if( clonep() )
  	  set_default_object(__FILE__);
	else {
	    set("unit", "��");
	    set("long", "һ��С���ӣ���������д�������������С�֣���ϸ������ֻ�ϳ��������֡�\n");
	    set("value", 10);
	}
	::init_item();
}



