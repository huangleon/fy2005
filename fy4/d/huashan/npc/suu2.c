// ; annie 6.28.03
// dancing_faery@hotmail.com
// ��ҹ�»���ˮ����������������������˸�� 
// ʱ����ʮһ�꣬��м����ֽ�����  - annie 07.03.2003

// �˲���֮�������� �̻�ɢ�� ��С�� 
// EXP 8M KEE 24K GIN/SEN 16K RESIST/ALL 60
// STR 80 DMG 60 ATTACK 116K DODGE 100K PARRY 100K
// IMMUNE TO BUSY,20SEC IMMORTAL,STEAL
// �����˺�����������ˮ�������������ϣ��ģ�

// A/D/P��Զ���ڱ�׼8M�����˿�TK��

inherit NPC;
#include <ansi.h>
#include <combat.h>
void smart_fight(object who);

void create()
{
        object armor,weapon;
        set_name("��С��", ({ "suu xiaoxiao","suu"}) );
        set("gender", "Ů��" );
        set("title","б������"NOR);
        set("nickname",WHT"�̻�ɢ��"NOR);
        set("age", 20+random(10));
        set("attitude","friendly");

        set("long",
                "��������֬�ۻ�����Щ΢�У�����������Ⱦ��ǳǳ����ۣ���\n���ǵ������Σ��·�˯���ѣ��������ڣ�ͷ����������б\n��һֻ������ӣ��������������£�����΢�г�ɫ��\n"
                );
        set("class","demon");
    	set("score", 10000);
        set("fle",50);
        set("cor",40);
        set("cps",30);
        set("str",20);
        set("per",200);
        set("force",2500);
        set("max_force",2500);
        set("atman",1500);
        set("max_atman",1500);
        set("mana",1500);
        set("max_mana",1500);

        set("no_fly",1);
        set("no_arrest",1);
                
        set("resistance/gin",60);
        set("resistance/kee",60);
        set("resistance/sen",60);
        
                set("NO_KILL","��˽������˵�Ů�ӣ����������̵��������֣�\n");

        set("max_kee",24000);
        set("max_gin",16000);
        set("max_sen",16000);
        

        set("chat_chance", 1);
        set("chat_msg", ({
                "��С������ˮ�����ڴ��ߣ������Ĵ���һ����Ƿ��\n",
                "��С��̾������ɽ�ɣ���ɽ�ɡ�����÷��Ȼ�Ǹ������õĶ�������ô��С�¶��첻�á�\n",
                "��С������ͷȥ����������һ�Է��ŵ������ĵ�ָ�ס�\n",
                }) );

    set("inquiry", ([
        "����":   "action��С������һ����Ƿ��ҡͷ��������Ҫ��������������飬���ɲ������ˡ�",
        "ħ��":   "action��С������һ����Ƿ��ҡͷ��������Ҫ��������������飬���ɲ������ˡ�",
        "�������":   "action��С������һ����Ƿ��ҡͷ��������Ҫ��������������飬���ɲ������ˡ�",
        "�������":   "action��С������һ����Ƿ��ҡͷ��������Ҫ��������������飬���ɲ������ˡ�",
        "����":   "action��С��������һ�ۣ�������������ô���������������ˣ�Ī���Ҳ�֪����",
        "��������":   "action��С��������һ�ۣ�������������������ô���������࣬Ī���Ҳ�֪����", // *snicker suu,*escape
        "��ɽ":   "�úõĴ�ˮ�������������ϣ�������ȥ��������������\n��Ҫ���Ű����ӳԷ������⻪ɽһ�ɣ�����Ҳ�ա�",
        "��ɽ��":   "�úõĴ�ˮ�������������ϣ�������ȥ��������������\n��Ҫ���Ű����ӳԷ������⻪ɽһ�ɣ�����Ҳ�ա�",
        "������":   "�úõĴ�ˮ�������������ϣ�������ȥ��������������\n��Ҫ���Ű����ӳԷ������⻪���������Ҳ�ա�",
        "��÷":   "��÷ô��������ı��ֻ�������������㲻���Ǹ�Ӣ�ۡ�",
        "��÷��ʦ":   "��÷ô��������ı��ֻ�������������㲻���Ǹ�Ӣ�ۡ�",
        "��ˮ����":   "��ˮ��������������ֱ���޵У�˭֪�������ɽ���Ӿ�\n�������������һ������磬���ǲ�������",
        "��������":   "��ˮ��������������ֱ���޵У�˭֪�������ɽ���Ӿ�\n�������������һ������磬���ǲ�������",
        "������":   "���������Ҷ��������������۵ı��£���ʲô���컨��\n��ֱ�����˶��춷����ĭ��ɵġ�",
        "���컨��":   "�����õ����컨��������ϣ�ȴҲ�ǵǷ��켫�����������ü���",
         ]) );


        setup();

        carry_object(__DIR__"obj/longskirt")->wear();


        set_temp("buff_type/blocked",1);        // ����֮��

}


int accept_object(object who, object ob)
{
        if (ob->query("name")==CYN"�һ�ľ��"NOR 
        	&& ob->query("id") == "taohua mupai" 
        	&& (REWARD_D->riddle_check(who,"��������") >= 6 
        		|| REWARD_D->check_m_success(who,"��������")))
        {
                command("sigh");
                command("say ������ʱ�����У�����\n");
                remove_call_out("greeting");
                call_out("greeting", 1,who);
                if (environment())
                	environment()->set("boss_out",time());
                return 1;
        }
        return 0;
}


void greeting(object ob)
{
        mapping data;
        
        message_vision(HIG"\n��С�������������ǶԵ�ָ�ף�̧��ͷ��������һЦ�����ְɡ�\n\n"NOR,ob);
        
        REWARD_D->riddle_done(ob,"��������",100,1);
        
        data = ([
				"name":		"��������",
				"target":	ob,
				"att_1":	"cps",
				"att_1c":	1,
				"mark":		1,
		]);
		
		REWARD_D->imbue_att(data);
			
        ob = new(__DIR__"suu");
        ob->move(environment());
        destruct(this_object());
}
