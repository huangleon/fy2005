inherit ITEM;

void create()
{
        set_name("��ȸͼ", ({ "design"}) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "��ȸ������ͼֽ�����Ǻ����Ǽٵġ�\n");
                set("unit", "��");
                set("value", 0);
		set("fake",1);
                set("material", "paper");
              }
        ::init_item();
}