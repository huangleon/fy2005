inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("�������ͷ��", ({ "lao zhang", "zhang" }) );
        set("gender", "����" );
        set("age", 57);
        set("long",
                "����ȷ�Ѻ����ˣ��뷢���Ѱ߰ף��˿��������������ͷ��������
����̯ͷ��ֽ�����ѱ�����Ѭ���ֺ��ֻƣ���������������\n");
		set("per", 5);
		set("combat_exp", 2000);
        set("attitude", "friendly");
        set("vendor_goods", ([
        	"obj/food_item/soup" : 120,
            	"obj/food_item/soup1" : 120,
            	"obj/food_item/soup2" : 120,
            	"obj/food_item/soup3" : 120,
            	"obj/food_item/soup4" : 120,
            	"obj/food_item/soup5" : 120,
        ]) );
        setup();
        carry_object("/obj/armor/cloth")->wear();

}

void init()
{
	::init();
        add_action("do_vendor_list", "list");
}

void reset()
{
        set("vendor_goods", ([
        	"obj/food_item/soup" : 120,
            	"obj/food_item/soup1" : 120,
            	"obj/food_item/soup2" : 120,
            	"obj/food_item/soup3" : 120,
            	"obj/food_item/soup4" : 120,
            	"obj/food_item/soup5" : 120,
        ]) );	
}