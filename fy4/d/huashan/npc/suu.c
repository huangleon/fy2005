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
        set("title",YEL"������� "NOR CYN"��������"NOR);
        set("nickname",WHT"�̻�ɢ��"NOR);
        set("age", 20+random(10));
        set("attitude","friendly");

        set("long", "��������֬�ۻ�����Щ΢�У�����������Ⱦ��ǳǳ����ۣ���
���ǵ������Σ��·�˯���ѣ��������ڣ�ͷ����������б
��һֻ������ӣ��������������£�����΢�г�ɫ��\n"
                );
        set("class","demon");
    	set("combat_exp", 8000000); 
    	set("score", 10000);
        set("str",20);
        set("per",200);
        set("force",2500);
        set("max_force",2500);
        set("force_factor",130+random(100));
        set("atman",1500);
        set("max_atman",1500);
        set("mana",1500);
        set("max_mana",1500);
		
		set("real_suu",1);
        set("no_fly",1);
        set("no_arrest",1);
                
        set("resistance/gin",60);
        set("resistance/kee",60);
        set("resistance/sen",60);

        set("max_kee",24000);
        set("max_gin",16000);
        set("max_sen",16000);
        
        set_skill("heavendance",250);
        set_skill("blade",200);

        set_skill("demon-steps",200);
        set_skill("fall-steps",200);
        set_skill("anxiang-steps",200);
        set_skill("cloud-dance",200);
        set_skill("move",200);
        set_skill("dodge",200);

	    set_skill("perception",800);

        set_skill("meihua-shou",210);
        set_skill("unarmed", 300);
        set_skill("force", 200);

        set_skill("lingxi-zhi", 170);
        set_skill("spells",200);
        set_skill("parry",200);
        set_skill("kwan-yin-spells",200);
        set_skill("five-steps",180);
        set_skill("stormdance",400);
        set_skill("move",200);
        set_skill("dodge",200);

        set_skill("spring-water",200);
        set_skill("iron-cloth",200);
        map_skill("iron-cloth","spring-water");

        set("chat_chance", 1);
        set("chat_msg", ({
                "��С������ˮ�����ڴ��ߣ������Ĵ���һ����Ƿ��\n",
                "��С��̾����"YEL"��ɽ��"NOR"����ɽ�ɡ���"YEL"��÷"NOR"��Ȼ�Ǹ������õĶ�������ô��С�¶��첻�á�\n",
                "��С��ƫͷ������һ�ۣ�˵������Ȼ���ˣ���ô�������֣�\n",
                "��С������ͷȥ����������һ˫���ŵ������ĵ�ָ�ס�\n",
                }) );

    set("inquiry", ([
        "����":   "action��С������һ����Ƿ��ҡͷ��������Ҫ��������������飬���ɲ������ˡ�",
        "ħ��":   "action��С������һ����Ƿ��ҡͷ��������Ҫ��������������飬���ɲ������ˡ�",
        "�������":   "action��С������һ����Ƿ��ҡͷ��������Ҫ��������������飬���ɲ������ˡ�",
        "�������":   "action��С������һ����Ƿ��ҡͷ��������Ҫ��������������飬���ɲ������ˡ�",
        "����":   "action��С��������һ�ۣ�������������ô���������������ˣ�Ī���Ҳ�֪����",
        "��������":   "action��С��������һ�ۣ�������������������ô���������࣬Ī���Ҳ�֪����", // *snicker suu,*escape
        "��ɽ":   "�úõ�"YEL"��ˮ����"CYN"��"YEL"��������"CYN"��������ȥ��������������\n��Ҫ����"YEL"������"CYN"�Է������⻪ɽһ�ɣ�����Ҳ�ա�",
        "��ɽ��":   "�úõ�"YEL"��ˮ����"CYN"��"YEL"��������"CYN"��������ȥ��������������\n��Ҫ����"YEL"������"CYN"�Է������⻪ɽһ�ɣ�����Ҳ�ա�",
        "������":   "�úõ�"YEL"��ˮ����"CYN"��"YEL"��������"CYN"��������ȥ��������������\n��Ҫ����"YEL"������"CYN"�Է������⻪���������Ҳ�ա�",
        "��÷":   "��÷ô��������ı��ֻ�������������㲻���Ǹ�Ӣ�ۡ�",
        "��÷��ʦ":   "��÷ô��������ı��ֻ�������������㲻���Ǹ�Ӣ�ۡ�",
        "��ˮ����":   "��ˮ��������������ֱ���޵У�˭֪�������ɽ���Ӿ�\n�������������һ������磬���ǲ�������",
        "��������":   "��ˮ��������������ֱ���޵У�˭֪�������ɽ���Ӿ�\n�������������һ������磬���ǲ�������",
        "������":   "���������Ҷ��������������۵ı��£���ʲô"YEL"���컨��"CYN"\n��ֱ�����˶��춷����ĭ��ɵġ�",
        "���컨��":   "�����õ����컨��������ϣ�ȴҲ�ǵǷ��켫�����������ü���",
         ]) );

        map_skill("spells","kwan-yin-spells");
        map_skill("unarmed", "lingxi-zhi");
        map_skill("force", "bolomiduo");
        map_skill("dodge","stormdance");
        map_skill("move","stormdance");
        map_skill("blade","heavendance");
        map_skill("parry","lingxi-zhi");
        
        set_skill("kaleidostrike",500);
        map_skill("unarmed", "kaleidostrike");

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight(this_object()) :),
        }) );


        setup();

        carry_object(__DIR__"obj/longskirt")->wear();
        carry_object(__DIR__"obj/qingcong")->wield();

        carry_object(__DIR__"obj/paper2");

        set("reward_npc", 1);
        set("difficulty",20);

        set_temp("buff_type/blocked",1);        // ����֮��

}

int fight_ob(object who)
{
        if (query("immortal"))
                who->remove_enemy(this_object());
        ::fight_ob(who);
        return 1;
}

int kill_ob(object who)
{
        object me;
        int exp_r,busyst;
        if (query("immortal"))
                who->remove_killer(this_object());
        ::kill_ob(who);
        stop_busy();
        smart_fight(who);
        return 1;
}

void do_ck(object * tar)
{
        int i;
        set("immortal",0);
        delete("NO_KILL");
        set("resistance/kee",60);
        set("resistance/gin",60);
        set("resistance/sen",60);
        return;
}

void force_busy(int busy)
{
        message_vision(CYN"\nһȦ����ɫ�Ĺ�â����С�����ǳǳ�ο���\n"NOR, this_object());
        return;
}

varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
        message_vision(CYN"\nһȦ����ɫ�Ĺ�â����С�����ǳǳ�ο���\n"NOR, this_object());
        return;
}

void smart_fight(object who)
{
        object me,target,item;
        object * tar;
        int i;
        me = this_object();

        if (who != me)
            target = who;
        else
            target = select_opponent();

        if ((query("kee") < query("max_kee") / 2 || query("gin") < query("max_gin") / 2 
        	|| query("sen") < query("max_sen") / 2) && query("timer/annie_immortal") + 180 < time())
        {
                message_vision(HIW"\n��С����ü���ף������޷��Զ�������һ�㵭��ǳǳ�Ĳ��⡣\n"HIC"΢��������ȦȦ��������$N�ĵ�������Ůһ�㣬���˲����᷸��\n\n"NOR, me);
                set("timer/annie_immortal",time());
                tar = query_enemy();
                for (i=0;i<sizeof(tar) ;i++ )
                        tar[i]->remove_killer(me);
                set("immortal",1);
                set("NO_KILL","��С������������һ�㵭��ɫ�Ĺ�â�������Ƶ�����֮�⡣\n");
                set("resistance/kee",100);      // ��������һЩֱ��rascal skill,����һ�� ; annie.
                set("resistance/gin",100);
                set("resistance/sen",100);
                call_out("do_ck",20,tar);
                return ;
        }

        if (query("immortal"))
        {
                tar = query_enemy();
                for (i=0;i<sizeof(tar) ;i++ )
                        tar[i]->remove_killer(me);
        }

    	tar = all_inventory(target);
        if (sizeof(tar) < 1)
                return;

        for (i=0;i<sizeof(tar) ;i++ )
        {
        	item = tar[i];
            if(item->query("skill_type") && !item->query("owner") && !item->query_temp("owner")) {
	        	message("vision",HIB"\nһ��΢�������������ƺ�����"+me->name()+"��Ӱ���ڷ�������һ�Ρ�\n", environment(me),me);
	        	message("vision",HIB"�������ۣ�ȴ����"+me->name()+"��Ȼ����ԭ�أ��ƺ�ʲô��û�з�����\n\n"NOR, environment(me),me);
	            tell_object(target, "��о�����һ�ᣬ�ƺ����˵㶫������\n\n");    	
	            item->move(me);
	            break;
        	}
        }
       return;

}


void die()
{
        object me,owner,enemy,paper,*sy_inv,things;
        int j;
        me = this_object();
        if (!query_temp("last_damage_from"))
        {
            sy_inv = all_inventory(this_object());
            for(j=0;j<sizeof(sy_inv);j++){
                    things = sy_inv[j];
                    destruct(things);
            }
            ::die();
            return;
        }
    	if(objectp(enemy=query_temp("last_damage_from")))
        if(owner=enemy->query("possessed"))
        	enemy = owner;
        
        if (environment(me)->query("short") != "��������" || !REWARD_D->check_m_success(enemy,"��������"))
        {
                set("reward_npc", 0);
                sy_inv = all_inventory(this_object());
                for(j=0;j<sizeof(sy_inv);j++){
                        things = sy_inv[j];
                        destruct(things);
                }
                ::die();
                return;
        }
        message_vision(CYN"\n$N��ͷ������գ����ĵ�̾�˿�����
$N˵�����ţ�Ҳ�������ˡ�
$N˵������Ե��ɢ��������ȥ��������ڹ����׹���ϡ���
$N˵�����ǻ���Сʱ�Ļ����ܻ���Ҫ�������ĳ��ĵİɡ���\n\n"NOR,me,enemy);
        enemy->set("annie/demon_killed_suu",1);
	//	REWARD_D->riddle_done(enemy,"����",100,1);
        ::die();
        return;
}



 
/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/

