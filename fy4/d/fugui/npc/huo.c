#include <ansi.h>

inherit NPC;
inherit F_PAWNOWNER;
inherit F_VENDOR;
void create()
{
	set_name("���Ƥ", ({ "huo bopi" }) );
	set("gender", "����" );
	set("title", "�����ϰ�");
	set("long","
���Ƥ��Ȼ�����ջ���ʵ��Ҳ��̫��Ƥ�������Ҳ�����ι������ϵ�
\n��ˮ���ѣ���Ȼ�ε��൱���ס���ֵ���Խ�������ˮ����Խ����
�֡�������������ֻ����˵�Ұ���ӣ������ձ������۾�˵����ʱ��
�������۽ǿ��������ʱ��ض��ڴ��������ϵĶ�������ֵ�������ӡ�\n");
    	
    	set("no_arrest",1);
    	set("richness",100000);
    	
    	set("chat_chance",1);
        set("age", 55);
    	set("chat_msg", ({
        "���Ƥ�޺޵�������˵������Ƕ���������������������ķ�������
���ࡱ�ֽ���������������û����ѽ����Ǯ�ò��Ĳź��أ�\n",
                                })  );

	set("combat_exp", 10000);
	set("attitude", "friendly");
	set("per",30);
	
	set_skill("unarmed",80);
        set_skill("dodge",100);
	setup();
	carry_object("/obj/armor/cloth")->wear();
}


void init()
{	
	::init();
        add_action("do_value", "value");
        add_action("do_pawn", "pawn");
        add_action("do_sell", "sell");
        add_action("do_redeem", "redeem");
	add_action("do_vendor_list","list");
}

void die(){
	object who = query_max_damage_dealer();
	if (!objectp(who))
		who = query_temp("last_damage_from");
		
	if (objectp(who))
		log_file("HIPPO_DEBUG", sprintf("%s,%s,killed huo bopi,%s\n",who->name(),who->query("id"),ctime(time())));
	::die();
	return;
}