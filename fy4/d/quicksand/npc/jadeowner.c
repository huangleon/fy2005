#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("�鱦��", ({ "jade seller", "seller" }) );
        set("gender", "����" );
        set("age", 49);
        set("long", "����һλ������˪�ĵ��ƹ�\n");
        set("combat_exp", 700000);
	
		set("max_kee", 2400);
		set("kee",2400);
	
		set("str", 300);
        set("attitude", "friendly");

		set("inquiry", ([
        	"�Ŷ���":	"�Ŷ������Ŷ�����ԭ����Ӣ�����������Ǹ�������̽�������ˡ�\n",
    	]) );
		        
        set_skill("blade", 130);
        set_skill("shortsong-blade", 100);
        set_skill("fall-steps", 130);
        set_skill("dodge", 100);
        set_skill("parry", 120);
        set_skill("move",100);
        map_skill("blade", "shortsong-blade");
        map_skill("parry", "shortsong-blade");
        map_skill("dodge", "fall-steps");
        map_skill("move","fall-steps");
        
        set("vendor_goods", ([
                __DIR__"obj/jade1":12,
                __DIR__"obj/jade2":12,
                __DIR__"obj/jade3":12,
                __DIR__"obj/jade4":12,
				BOOKS"skill/buddhism_50b":12,
				"/obj/medicine/snake_drug":12,
				__DIR__"obj/amber1":3,
        ]) );

        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/jadeblade")->wield();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}


void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( " ���ƹ�Ц�ŵ�����λ"
                                + RANK_D->query_respect(ob)
                                + "���������� \n");
                        break;
                case 1:
                        say( " ���ƹ�Ц�ŵ�����λ"
                                + RANK_D->query_respect(ob)
                                + "�����Ǽ���֮���Į���飬������һ�鵲�ְɡ� \n");
                        break;

        }
}


void reset()
{
        set("vendor_goods", ([
                __DIR__"obj/jade1":12,
                __DIR__"obj/jade2":12,
                __DIR__"obj/jade3":12,
                __DIR__"obj/jade4":12,
		__DIR__"obj/jademonk":12,
		"/obj/medicine/snake_drug":12,
		__DIR__"obj/amber1":3,
        ]) );
}



int accept_object( object who, object item){
		
		if (item->query("name") == HIM"�Ͼ���ʯ"NOR && item->query("jile")==1){
			if (REWARD_D->riddle_check(who,"�Ͼ�֮��")==2 
				|| REWARD_D->riddle_check(who,"�Ͼ�֮��/�鱦��")) {
				command("shake");
				command("say �㻹�����Ҹ��˰ɡ�");
				return 0;
			}
			
			message_vision(CYN"$N����"+item->query("name")+NOR+CYN"���˼��£����ó�����Ƭ����Ƭ�̣�üͷ������\n"NOR, this_object());
			command("say ǰЩ���Ӻ������˴������ﾭ����������ô����ʯ��");
			command("say ������������о��ɫ����ûʲô̫���ֵ��");
			command("shake");
			REWARD_D->riddle_set(who,"�Ͼ�֮��/�鱦��",1);
			
			if (sizeof(who->query("riddle/�Ͼ�֮��"))==4) {
				tell_object(who, CYN"\n"+name()+CYN"˵��ֻ��һ���˻�֪����鱦ʯ���������������ֽйŶ�����
��˵������������͸������ϵ��ڹ�Ĺ���ת����ڵ��׵�����ת�ı��
û������֪�������ģ���һ��֪���ⱦʯ�ĵ�ϸ��\n");
				REWARD_D->riddle_set(who,"�Ͼ�֮��",2);
			}
			
			return 0;
		}
			
		if (item->query("thief_obj")){
			command("say С�겻����������֮�");
			return 0;
		}
				
}