inherit ITEM;

void create() {
	set_name("����", ({ "deadwolf" }) );	
	set_weight(80000);
	set("long", "��������ˤ��Ƥ�����ã��ԿǱ�⡣��Ϊ�� 
ˤ�����ˣ�һ�����������˳����������˵ġ�Ҳ
��֪���Ӷ�ߵĵط�����������ˤ�������� \n");
	set("unit", "��" );
	set("value", 1);
	set("deadwolf",1);
    if( clonep() )
       set_default_object(__FILE__);

}

