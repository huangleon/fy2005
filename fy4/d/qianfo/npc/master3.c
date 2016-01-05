#include <ansi.h>
#include <combat.h>
inherit NPC;
inherit F_MASTER;
int leave();

void create()
{
    set_name("�����ʦ", ({"master dingbang", "master", "dingbang" }) );
    set("gender", "����");
    set("long", "
�����ʦ���˹���ʦ��ʦֶ������������Ժ��Ҳ������һЩ�׼ҵ��ӣ�
����𷨡�\n");
    	set("age", 74);
    	set("attitude", "peaceful");
    	set("class", "bonze");
    	set("apprentice_available", 3);

    	set("reward_npc", 1);
	set("difficulty", 5);
    	
    	set("combat_exp", 1200000);
    	set("score", 9000);
    	
    	set_skill("unarmed", 120);
    	set_skill("dabei-strike",120);
    	set_skill("force", 120);
    	set_skill("dodge", 120);
    	set_skill("literate", 100);
    	set_skill("chanting", 120);
    	set_skill("parry", 120);
    	set_skill("lotusforce", 120);
    	set_skill("buddhism", 100);
    	set_skill("nodust-steps",120);
    	set_skill("staff",120);
    	set_skill("cloudstaff",120);
    	set_skill("perception", 100);
    	set_skill("foreknowledge", 100);
	set_skill("move", 100);
	set_skill("magic", 100);
	set_skill("essencemagic", 100);
    	    	
    	map_skill("force", "lotusforce");
    	map_skill("dodge","nodust-steps");
    	map_skill("unarmed","dabei-strike");
    	map_skill("staff","cloudstaff");
    	map_skill("parry","cloudstaff");
    	map_skill("magic","essencemagic");
    	

 	set("guard_msg",HIW"$N�ȵ��������ӷ�,����������������ȴҲ���������꣬ʩ�����ˣ���\n"NOR);
 	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.qianshouqianbian" :),
        }) );
         set("inquiry", ([
        	"leave" : (: leave :),
    	]));
 
    	create_family("�˹�����", 4, "��ʦ");
		set("rank_nogen",1);
		set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
					
		set("ranks",({"Сɳ��","С����","��ɽɮ","����ɮ","����ɮ","����ɮ","����ɮ","����ɮ",
		"���´�ʦ","�����޺�","�������","������ɮ",YEL"����ʥɮ"NOR,YEL"�������"NOR,
		YEL"�����ڴ���"NOR,HIY"����������"NOR}));				
		
    	setup();
    	carry_object(__DIR__"obj/staff")->wield();
    	carry_object("/obj/armor/cloth")->wear();
}


void attempt_apprentice(object ob)
{
              
    	if (ob->query("once_menpai/bonze")&& ob->query("class")!="bonze") {
			command("shake");
			command("say ʩ�������޳���û�����֮�ġ�\n");
			return;
		}
 		if(ob->query("marry") && !ob->query("jiebai")){
			message_vision("$Ņͷ���˿�$n����λʩ������δ����������ذɡ�\n", 
				this_object(), ob);
			return;
		}		
    	if (ob->query("gender")!="����") {
    		message_vision("$N˵�����²���Ůͽ��\n",this_object());
    		return ;
    	}	
    	ob->set("class","bonze");
    	command("say �����ӷ����գ����գ�");
    	command("recruit " + ob->query("id") );
}


int accept_fight(object me)
{
    	if( (string)me->query("class")=="bonze" )
        	command("say �����ӷ𣡳����˽��ǿ�񶷣����Ĳ���Υ����档");
    	else
        	command("say ʩ����Ȼ�����գ�����������ǣ�Ҳ���ؽ����ˡ�");
       	return 0;
}


void init()
{	
	::init();
	add_action("do_killing", "kill");

}


int leave() {
	if (this_player()->query("class")!="bonze") return 0;
	message_vision(CYN"$N���Ƶ��������ӷ𣬼�����Ե���α��������Ժ�Ҳ��Ҫ�ٻ����ˡ�\n"NOR, this_object(),this_player());
	message_vision(CYN"$N˵�����ŵ���ͨ�����ķ��ǵ��Ӳ���ʹ�á�\n"NOR,this_object(),this_player());
	return 1;
}

