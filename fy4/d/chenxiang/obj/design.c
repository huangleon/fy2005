inherit ITEM;

void create()
{
        set_name("��ȸͼ", ({ "design"}) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "��ȸ������ͼֽ���ϱ����������Ļ��˲��ٷ��š�\n");
                set("unit", "��");
                set("value", 0);
		set("real",1);
                set("material", "paper");
              }
	::init_item();
}
