// 
inherit NPC;
inherit F_VENDOR;

void create()
{
    	set_name("�������ͷ", ({ "rednose man", "man" }) );
    	set("gender", "����" );
	set("nickname", "�������Ƶ�");
    	set("age", 50);
    	set("long","
���������������ڣ�������ȴ����������֪������������������
Ϊ�����ӹ��ò������������Լ�ȴ���ú����⡣ \n");
	set("per", 4);
	set("combat_exp", 2000);
    	set("attitude", "friendly");
   	set("chat_chance", 1);
   	set("chat_msg", ({
   		"�������ͷ���������е������������ġ���Ҷ�࡯һ���¶��о���������
�Ǿ����㣬�����¡��ǣ�����Ҳ���硣\n",
		"�������ͷ�����е������������ġ���Ҷ�࡯���͹��Ǻ�����ɣ��������
��������������Ҳ�Ȳ��������ĺþ��ˡ�\n", 
 	}));

    	set("vendor_goods", ([
    		"/obj/food_item/winebowl" : 120,
    		"/obj/food_item/horsebean" : 120,
    		"/obj/food_item/peanut" : 120,
    	]) );
    	setup();
    	carry_object("/obj/armor/cloth")->wear();
}


void init()
{
	::init();
        add_action("do_vendor_list", "list");
}

void reset(){

    	set("vendor_goods", ([
    		"/obj/food_item/winebowl" : 120,
    		"/obj/food_item/horsebean" : 120,
    		"/obj/food_item/peanut" : 120,
    	]) );	
	
}