inherit ITEM;

void create()
{
        set_name("ֽ��", ({"paper", "ֽ"}) );
	set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ��մ��Ѫ��ֽ�������¹⣬����Լ���Կ�����
	
	������������������������
	
\n");
                set("value", 0);
        }
	::init_item();
}
