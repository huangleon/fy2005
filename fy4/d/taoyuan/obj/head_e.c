inherit ITEM;
void create()
{
    	set_name("ͷ­��", ({ "skull"}) );
    	set_weight(500);
    	set_max_encumbrance(1000);
		set("skull",1);
    	set("recovered",1);
    	if( clonep() )
    		set_default_object(__FILE__);
    	else {
        	set("unit", "��");
        	set("long", "
һ��ͷ­�ǣ�ͷ�ǰٻ�Ѩ�ĵط�����һ���ߴ糤��������������ͷ����
ȫ���������ڣ��������ͷ­�ǵ��۾��Ѿ��õ������û�����ִ��˵�
����ͷ­�ϵļ�����Ȼ�Ѿ�ȫ�����ã�ȴ������ճ�����룬��ϡ����
���䵱�������������ӡ�\n");
        	set("value", 1);
    	}
    	::init_item();
}

// int is_container() { return 1; }




