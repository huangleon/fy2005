#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

int kill_him();

void create()
{
        set_name("ʲôҲ������", ({ "bad seller","seller" }) );
        set("gender", "����" );
        set("age", 40);
		set("combat_exp", 700000);

		set("long","����˴���������·�ߣ���ǰ����һ���С̯�����õ��Ͳ���
�Ͳ���д����������ɽ������֣�����տյ�����ʲô����Ҳû�С�\n");
        set("chat_chance", 1);
        set("chat_msg", ({
                "ʲôҲ����������ҡͷ��̾����������������ʲô������������\n",
        }) );


		set_skill("whip",200);
		set_skill("dragonwhip",125);

		map_skill("whip","dragonwhip");

		set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
              (: perform_action, "whip.thousandfeather" :),
        }) );

        set("inquiry", ([
                "��������ɽ":  (: kill_him :),
                "�������":	"actionʲôҲ����������ҡͷ��̾�������̣����̣�ʲô�����̣�����\n",
                "��":	"actionʲôҲ����������ҡͷ��̾�������̣����̣�����ʲô�����̣�����\n",				
        ]) );

        set("attitude", "friendly");
        set("vendor_goods", ([
//			__DIR__"obj/niren":20,
        ]) );
        setup();
        carry_object("obj/armor/cloth",([	"name": HIR"Ѫ��"NOR,
    						"long": "һ��մ����Ѫ���·�\n",
    						 ]))->wear();  
        carry_object("obj/weapon/whip",([	"name": "����",
    						"long": "��������ɽ���������õı�����\n",
    						"value": 0,
    						 ]))->wield();  

}

void init()
{
        ::init();
        add_action("do_vendor_list", "list");
}

int kill_him()
{
	object me,ob=this_object();
	me = this_player();
	message_vision("$N����һ��Ŀ��ңԶ����ʣ��૵����Ƕ��ǹ�ȥ�����ˣ������������������\n",ob);
	return 1;
}



int accept_object(object who, object ob)
{
	object oc;
	if (crypt(ob->query("value")+"","ydiN9HFOAOtZ2") != "ydiN9HFOAOtZ2")
	{
			ccommand("shake");
			ccommand("say ʲô�������������ʲôҲ������");
			return 0;
	}
	ccommand("emote Ŀע"+who->name(1)+"���ã�������̾�˿��������˵�ͷ��");
	if (query("still"))
	{
		if (stringp(query("still")))
			ccommand("say ��Ȼ���г�����Ҫ�������������Ѿ���������"+query("still")+"�ˡ�");
		else
			ccommand("say ��Ȼ���г�����Ҫ�������������Ѿ��������˱����ˡ�");
		
		return 0;
	}
	ccommand("say ��Ȼ���г�����Ҫ���ұ�����ɡ�");
	set("still",who->name());
	oc=new("/obj/book/swimming_50.c");
	oc->move(who);
	ccommand("emote �ݸ�"+who->name(1)+"һ�����Ƶ�С���ӡ�");
	return 1;
}

	
void reset(){
	if (!random(4))
		set("still",0);
	
}


 
/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/

