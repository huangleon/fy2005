// Silencer @ FY4 workgroup. Oct.2004

inherit ITEM;
inherit F_FOOD;
void create()
{
    	set_name("����ͷ", ({ "mantou" }) );
    	set_weight(8000);
    	if( clonep() )
        	set_default_object(__FILE__);
    	else {
        	set("long", "
���������Ǹ֣��ڷ����ﲻ�Բ�����Ȼ������������������еĻָ�����ֹͣ��
���Ե����ʳ����ˮ���˾�Ҫ��ʱ���䡣����һ��������Ĵ���ͷ���������
��������������������ԡ�\n");
        	set("unit", "��");
        	set("value", 0);
        	set("no_drop", 1);
        	set("food_remaining", 100);
        	set("food_supply", 300);
    	}
    	::init_item();
}


