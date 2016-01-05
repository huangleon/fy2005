inherit SMART_NPC;
#include <ansi.h>
int kill_him();

void create()
{
        set_name("л����", ({ "xie changqing" }) );
        set("gender", "����");
        set("age", 25);
        set("long",
"һ�������Ӣ�������꣬�������ڲ����ţ�Ӣ���������ϣ�Ҳ����
һ������֮ɫ����\n"
);
      
      	set("chat_chance", 1);
	set("chat_msg", ({
"л�����૵������һ����ᣬ�Ҳ��ܾ�����������Ϣ����ȥ��������ʱ
�����������ˣ���ʹ����������֮�£�����˭�ᴫ����ȥ����������
���˶���Ϊ�Լ�����ɡ���\n",
	}) );

        set("inquiry", ([
            "÷ɽ��" : (: kill_him :),
            "mei shanmin" : (: kill_him :),
             ]));
		set("fly_target",1); 
        set("attitude", "friendly");
        set("title",HIG"���"NOR);
        set("nickname", HIG"��Ӣ��"NOR);
        set("score", 0);
        set("reward_npc", 1);
		set("difficulty",2);
		set("class","legend");
       
        set("combat_exp", 3800000);        
        
//      set("perform_busy_d", "legend/dodge/fall-steps/luoyeqiufeng");
		set("perform_busy_u", "legend/unarmed/meihua-shou/meihai");
		set("perform_weapon_attack", "legend/sword/diesword/caidiekuangwu");
		set("perform_buff_1", "legend/force/qidaoforce/juqi");
		
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(20) :),
        }) );
          
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 150);
        set_skill("unarmed", 150);
        set_skill("sword", 200);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("magic",150);
                
        set_skill("qidaoforce", 150);
		set_skill("fall-steps",200);
		set_skill("meihua-shou",200);
        set_skill("diesword",200);
        
        map_skill("unarmed","meihua-shou");
        map_skill("force", "qidaoforce");
        map_skill("dodge","fall-steps");
        map_skill("move","fall-steps");
        map_skill("parry","diesword");
        map_skill("sword","diesword");
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup();

        carry_object("/obj/weapon/sword")->wield();
		carry_object("/obj/armor/cloth")->wear();
}

int kill_him()
{
        object me;
        me = this_player();
        if (this_object()->is_fighting()) return 1;
        message_vision(CYN"л�������˰���˵:������ƽ���֮��....\n"NOR,this_object());
        message_vision(CYN"л����ͻȻ�������г���������Ƭ�̣���Ȼ�ӽ���������һ��������δЪ��
�������֣����ǡ�������һ����ֻ����˫����Ѫ���죬��ֻ��ķָ������ϣ���
����ʳ��ָ���ų�������һ��������Ӣ��������һȦ����ֱ�ɶ��������ˡ���һ
�����������ϣ���������С��ؽ�������ҡ��ε�������ͷҲ���ص�ȥ�ˡ�\n"NOR,this_object());
        me->set("marks/л����",1);
        destruct(this_object());
        return 1;
}