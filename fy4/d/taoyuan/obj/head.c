//TIE@FY3
inherit ITEM;
void create()
{
    	set_name("ͷ­��", ({ "skull"}) );
    	set_weight(500);
    	set_max_encumbrance(1000);
		set("skull",1);
    	if( clonep() )
    		set_default_object(__FILE__);
    	else {
        	set("unit", "��");
        	set("long", "
һ���븯�õ�ͷ­�ǣ�ɢ����һ�ɶ����ͷ�ǰٻ�Ѩ�ĵط�����һ����
�糤��������������ͷ����ȫ���������ڣ��������ͷ­�ǵ��۾��Ѿ�
�õ������û�����ִ��˵�����\n");
        	set("value", 1);
    	}
    	::init_item();
}

// int is_container() { return 1; }




