inherit ITEM;

void create()
{
	set_name("���ǲ�", ({"grass", "wang you"}) );
	set_weight(20);
	if( clonep() )
  	  set_default_object(__FILE__);
	else {
	    set("unit", "��");
	    set("long", "һ����̵Ĳݣ��Ȼ�����������仹�̡�\n");
	    set("value", 1000);
	}
	::init_item();
}



