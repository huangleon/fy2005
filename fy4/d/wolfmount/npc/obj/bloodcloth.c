inherit ITEM;

void create()
{
        set_name("Ѫ��", ({ "blood cloth", "bloodcloth"}) );
	set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("unit", "��");
                set("long", "һ��������Ѫ���·���������Ѫд�˼�����Ŀ���ĵĴ��֣�
	����磬������ɽ�����ң���
        
        С��
\n");
	}
        set("value", 0);
        ::init_item();
}

