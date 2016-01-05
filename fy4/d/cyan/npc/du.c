// ; annie 07.2003
// dancing_faery@hotmail.com
// 
// �˲���֮��¥���� �����辡 �ž�ɽ 
// EXP 8M KEE 24K GIN/SEN 16K RESIST/ALL 60
// STR 100 DMG 25 ATTACK 71K DODGE 80K PARRY 71K
// 99% follow rules.

// A/P�����ڱ�׼8M��D�����ڱ�׼8M�����˿�TK��

inherit NPC;
#include <ansi.h>
#include <combat.h>
void smart_fight();

void create()
{
        object armor,weapon;
        set_name("�ž�ɽ", ({ "du junshan","du"}) );
        set("gender", "����" );
        set("title",YEL"������� "NOR CYN"��¥����"NOR);
        set("nickname",HIG"�����辡"NOR);
        set("attitude","friendly");

        set_temp("condition_type",NOR CYN" <������>"NOR);

        set("long",
                "����������㣬רע�����е�Ҷ�ѣ���ͷ�ĳ����ڷ��з���Ʈ�裬\n���������µ���ľ�ڳ���һ�������ľ���\n�˷ھ�䲣��Բ���Ī������֮�ӣ����޶ȣ����޶ȣ��������·��\n"
                );
        set("class","legend");
    set("combat_exp", 8000000); 
    set("score", 10000);
        set("fle",50);
        set("cor",40);
        set("cps",30);
        set("str",40);
        set("per",200);
        set("force",2500);
        set("max_force",2500);
        set("force_factor",130+random(100));
        set("atman",1500);
        set("max_atman",1500);
        set("mana",1500);
        set("max_mana",1500);

        set("no_fly",1);
        set("no_arrest",1);
                
        set("resistance/gin",60);
        set("resistance/kee",60);
        set("resistance/sen",60);

        set("max_kee",24000);
        set("max_gin",16000);
        set("max_sen",16000);

        set("chat_chance", 1);
        set("chat_msg", ({
                "�ž�ɽ����Ҷ�ѣ�������̾��������⣬����գ���Ȫ·�ϲ���ꣻ������⣬����գ�����ǰ��·��ͬ������\n",
                }) );

        set_skill("demon-blade",240);
        set_skill("blade",200);

        set_skill("demon-steps",200);
        set_skill("fall-steps",340);
        set_skill("anxiang-steps",200);
        set_skill("cloud-dance",200);
        set_skill("move",200);
        set_skill("dodge",200);

        set_skill("demon-force",200);
        map_skill("force","demon-force");

    set_skill("perception",200);

        set_skill("meihua-shou",210);
        set_skill("unarmed", 300);
        set_skill("force", 200);

        set_skill("lingxi-zhi", 170);
        set_skill("spells",200);
        set_skill("parry",200);
        set_skill("kwan-yin-spells",200);
        set_skill("five-steps",180);
        set_skill("move",200);
        
        map_skill("spells","kwan-yin-spells");
        map_skill("unarmed", "lingxi-zhi");
        map_skill("force", "bolomiduo");
        map_skill("dodge","fall-steps");
        map_skill("move","anxiang-steps");
        map_skill("blade","demon-blade");
        map_skill("parry","demon-blade");
        
        add_temp("apply/iron-cloth", 200);
        
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );

        setup();

        carry_object(__DIR__"obj/zhuye")->wield();
        carry_object(__DIR__"obj/bamboocloth")->wear();

    set("reward_npc", 1);
        set("difficulty",7);

}

void init()
{
        if (!is_fighting())
                set_temp("condition_type",NOR CYN" <������>"NOR);
        add_action("do_answer","answer");
}

object select_opponent()        
{
        object * enemy;
        int i;
        enemy = query_enemy();
        if(!sizeof(enemy)) {
                return 0;
        }
        clean_up_enemy();
        if(!sizeof(enemy)) {
                return 0;
        }
        for(i=0; i<sizeof(enemy); i++)
                if (userp(enemy[i]))
                        return enemy[i]; // focus user. ; annie 6.25.03
        return enemy[random(sizeof(enemy))];
}

int kill_ob(object who)
{
        // Ҫ��silencer��rascal!! >"<
        object me;
        int exp_r,busyst;
        ::kill_ob(who);

        delete_temp("condition_type");

        stop_busy();
        who = select_opponent();        // ѡ������npc����
        me = this_object();
        if (me->query("combat_exp") * 9 / 8 >= who->query("combat_exp"))        // 9350,%93
                busyst=1;
        else
                busyst=2;

        set("busy_type",busyst);
        set("enemy_id",who->query("id"));


        map_skill("dodge","fall-steps");
        perform_action("dodge.luoyeqiufeng "+query("enemy_id"));

        if (busyst == 1)
        {
                set("class","huashan");
                map_skill("dodge","cloud-dance");
                perform_action("dodge.yexuechuji "+query("enemy_id"));
                set("class","legend");
        }
        else
        {
                ccommand("unwield zhuye");
                map_skill("unarmed","meihua-shou");
                perform_action("unarmed.meihai "+query("enemy_id"));
                ccommand("wield zhuye");
        }

set_temp("a",1);
smart_fight();

        return 1;
}

void smart_fight()
{
        int i;
        int j;
        object *enemy, who,target,me,weapon,wpx;
        string msg;
        who = this_object();
        me=this_object();
        if (who->is_busy()) return;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        if (i>2 && enemy[1]->is_zombie()) {
                who->cast_spell("zombie-bolt");
                return;
        }

        target = present(query("enemy_id"),environment());
        if (!target)
                return;

        weapon = present("zhuye",me);
        if (!weapon)
        {
                message_vision(HIG"�ž�ɽ���κ�Ȼ��ת��Ʈ�䵽���������һƬϸ������Ҷ�������С�\n" NOR,who);
                weapon=new(__DIR__"obj/zhuye");
                weapon->move(me);
                weapon->wield();
        }

        if ((query("kee") < 1500 || query("sen") < 1500 || query("gin") < 1500) && !query("kianmo"))
        {
                set("kianmo",1);
                message_vision(WHT"�ž�ɽ�����Ϻ�Ȼ�Գ�һ˿��Ȼ֮ɫ������\n" NOR,who);
                message_vision(HIR"�ž�ɽһҧ��⣬�۵����һ����Ѫ�������˺�Ȼ��þ���ٱ���\n" NOR,who);
                this_object()->full_me();
//                "/cmds/imm/full"->main(this_object(),"");
                set("force_factor",query("force_factor")*2);
        call_out("do_kianmo", 4, this_object());
        }

        if (target->query("kee") < 4000 && query("busy_type") == 1)
        {
                map_skill("dodge","demon-steps");
                perform_action("blade.tiandirenmo "+query("enemy_id"));
                map_skill("dodge","fall-steps");
                return;
        }

        if (target->is_busy() && !query_temp("a"))      // Busy tick
                return;
        
        delete_temp("a");

        map_skill("dodge","fall-steps");
        perform_action("dodge.luoyeqiufeng "+query("enemy_id"));

        if (query("busy_type") != 1)
        {
                j=0;
                if (!target->query_temp("weapon") && target->query_skill_mapped("unarmed")=="lingxi-zhi")
                        j=1;
                if (wpx=target->query_temp("weapon"))
                        if (wpx->query("skill_type")=="sword" && target->query_skill_mapped("sword")=="xiaohun-sword")
                                j=1;
                if (wpx=target->query_temp("weapon"))
                        if (wpx->query("skill_type")=="whip" && target->query_skill_mapped("whip")=="xiaohun-whip")
                                j=1;

                if (j < 1 && !target->query_busy())
                {
                        ccommand("unwield zhuye");
                        map_skill("unarmed","meihua-shou");
                        perform_action("unarmed.meihai "+query("enemy_id"));
                        ccommand("wield zhuye");
                        return ;
                }

        }
        else
        {
                set("class","huashan");
                map_skill("dodge","cloud-dance");
                perform_action("dodge.yexuechuji "+query("enemy_id"));
                set("class","legend");
                map_skill("dodge","fall-steps");
        }

        if (!target->is_busy()) // Busy failed,self busy
                return ;

        if (target->query("kee") < 5500)        
        {
                map_skill("dodge","demon-steps");
                perform_action("blade.tiandirenmo "+query("enemy_id"));
                map_skill("dodge","fall-steps");
                return;
        }

        switch (random(5))
        {
        case 0:
                msg = HIY  "$N���һ��������"GRN"ϸ������Ҷ"HIY"ʹ����ת���Ǵ����еģ۷��������ݣ���������ˣ���ط�����һ����" NOR;
        me->add_temp("apply/attack",100);
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-100);
                msg = HIY  "$N����һ�У���һ����������һ������" NOR;
        me->add_temp("apply/attack",100);
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-100);
        msg = HIY  "$N��Ȼ������ͷ������һ������һ����" NOR;
        me->add_temp("apply/attack",100);
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-100);
                if (me->query_busy()<2) 
                        me->start_busy(2);
                return;
                break;
        case 1:

                me->add_temp("apply/attack", 150);
                me->add_temp("apply/damage",200);
        msg = HIR  "$N��Хһ������������˫�ۣ����е�"GRN"ϸ������Ҷ"HIR"�ó����������۷�������������һ���ǳɣ���籩���ع���$n��\n\n��һʽ��������Ұ��"NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIB  "�ڶ�ʽ�������ĺ�����"NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIC  "����ʽ��������죡����"NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                me->add_temp("apply/attack", -150);
                me->add_temp("apply/damage", -200);
                if (me->query_busy()<2) 
                        me->start_busy(2);              
                return;
                break;
        case 2:
                me->add_temp("apply/attack",200);
                msg = HIY  "$N���е�"GRN"ϸ������Ҷ"HIY"�趯���ٶ��������죬������������\n������"GRN"ϸ������Ҷ"HIY"ͻȻ������������$n����һʽ������������������\n" NOR;
                message_vision(msg,me,target);
                msg = HIY  "��⣡" NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                msg = HIY  "��ʯ��" NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                msg = HIY  "����ɽ��" NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                msg = HIY  "��������" NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                msg = HIC  "�ƾ�����" NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                        me->add_temp("apply/attack",-200);
                if (me->query_busy()<2) 
                        me->start_busy(2);              
                return;
                break;
        case 3:
                me->add_temp("apply/attack", 220);
                me->add_temp("apply/damage", 220);
                msg = HIR
                "$N����Ҷ�������е�"GRN"ϸ������Ҷ"HIR
                "���ȣ���һ����������������$n��ȥ��" NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                me->add_temp("apply/damage", 220);      
                msg = HIR"$N�������������һ�������е�"GRN"ϸ������Ҷ"HIR
                        "���ž���֮����$nϯ���ȥ��" NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                me->add_temp("apply/attack", -220);
                me->add_temp("apply/damage", -220-220);
                if (me->query_busy()<2) me->start_busy(2);
                return;
                break;
        case 4:
                me->add_temp("apply/attack", 120);
                msg = YEL  "$N��߳һ����һ��ϸ������Ҷ����Ҷ�ϸ��ŵ�����ˮ�龹Ȼ�׷׷ɳ���\n"CYN"����"+HIC"  ��"+HIG"  ��"+HIY"  ��"+HIR"  ��"+NOR CYN" �����ڳ�ÿһ���ˣ�\n" NOR;
                message_vision(msg,me);
                weapon->set("name","ˮ��");
                for (i=0; i<6;i++)
                {
                        msg=HIY"�׷ɵ�ˮ������$n��$l����"NOR;
                        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                }
                weapon->set("name","ϸ������Ҷ");
                me->add_temp("apply/attack", -120);
                if (me->query_busy()<2) me->start_busy(2);
                return;
                break;

        }
        return;
}


int do_kianmo()
{
        if (!is_fighting() || query("kee") < 1)
        {
                set("force_factor",query("force_factor")/2);
                return 0;
        }
        receive_damage("kee",query("max_kee")/5);
        receive_damage("sen",query("max_sen")/5);
        receive_damage("gin",query("max_gin")/5);
    call_out("do_kianmo", 4, this_object());
        return 1;
}


int accept_fight(object me)
{
        int flag = 6;   // shui xin feng suu gao du chu sen
        if (me->query("annie/demon_killed_shui"))
                flag--;
        if (me->query("annie/demon_killed_xin"))
                flag--;
        if (me->query("annie/demon_killed_feng"))
                flag--;
        if (me->query("annie/demon_killed_suu"))
                flag--;
        if (me->query("annie/demon_killed_gao"))
                flag--;
        if (me->query("annie/demon_killed_sen"))
                flag--;
        if (flag)
        {
                message_vision(CYN"�ž�ɽͣ�����е�Ҷ�ѣ�ͷҲ���أ�����ԭ������Σ�ڵ�Ϧ���㻹����Ͼ�������д����գ���\n"NOR,me);
                message_vision(CYN"$N�ɻ�Ŀ��Ŷž�ɽ��\n"NOR,me);
                message_vision(CYN"�ž�ɽ��Ц������Ī���㻹��֪�����Ϲ�С���������֡��䵱�����ơ����塢��ɽ��\n����ԭ��ÿһ�������У��������������ε��ˣ���\n("YEL"answer yes"CYN"/"YEL"no"CYN")\n"NOR,me);
                me->set_temp("annie/demon_du",1);
        }
        else
        {
                message_vision(CYN"�ž�ɽ̾�����������������������ˡ�\n"NOR,me);
                message_vision(CYN"�ž�ɽ̾�������ְգ������Һ�����Ȼ�Ὣ����ɽׯ�İ�׮�����㡣\n"NOR,me);
                message_vision(CYN"�ž�ɽ������һ�ۣ��ֵ�����Ҫ���ǣ������ֿɾ������������顣\n\n"NOR,me);
                me->set("annie/demon_du",1);
        }
        return 0;
}

int do_answer(string arg)
{
        object me = this_player();
        if (!me->query_temp("annie/demon_du"))
                return 0;
        if (!arg)
                return 0;
        if (arg != "yes" && arg != "no")
                return 0;
        
        me->set_temp("annie/demon_du",0);

        if (arg == "no")
        {
                message_vision(CYN"�ž�ɽ�ߵ����������Ѿ�֪���ˡ�\n"NOR,me);
                return 1;
        }


        if ( !me->query("maze/��ս��Ǯ"))
        {
                message_vision(CYN"�ž�ɽ�ߵ�����Ȼ֪�����㻹�пմ������\n"NOR,me);
                return 1;
        }
        message_vision(CYN"$N˵������������Ϲٽ����������Ǯ��Ҳ�������߽⣬����[Σ�ڵ�Ϧ]����\n"NOR,me);
        message_vision(CYN"����Ϊ����ЩǱ�����˲�����ֹ�㣿���ž�ɽ������¶����һ˿��ڽ����ɫ��\n"NOR,me);
        message_vision(CYN"�����֪���յ��ҽ̲����������������Ϲ�С�ɣ����֪�������µĲ��ǽ�Ǯ���ӣ������ҽ����ˣ���\n"NOR,me);
                return 1;

}

void unconcious()
{
        die();
        return;
}

void die()
{
        object me,owner,enemy;
        me = this_object();
        if (!query_temp("last_damage_from"))
        {
                ::die();
                return;
        }
    if(objectp(enemy=query_temp("last_damage_from")))
        if(owner=enemy->query("possessed"))
                        enemy = owner;
        if (enemy->query("annie/demon_du") != 1)
        {
                ::die();
                return;
        }
        message_vision(HIR"$N�������һ����Ѫ����Ȼ�ȵ���ס�֣�\n"NOR,me);
        me->remove_all_killer();
    	me->full_me();    
//      "/cmds/imm/full"->main(me,"");
        set("NO_KILL",1);
        enemy->start_busy(40);  // PK�����˻�ɱ��....escape
        start_busy(40);
        call_out("do_exc",2,me,enemy,0);
        return;
}

void do_exc(object me,object target,int count)
{
        string msg;
        string *event_msg = ({
"$N��һ����ֵ�������$n���������о��������־��ȣ��������ɣ����ָм���\n",
"$N������ǰ�������˿ڣ������Ķ�$n˵���������ֲ������ܻ������ǡ�\n",
"�ǲ��Ǿ�����֣�Ϊ����Ҫ������˽��й¶���㣿\n",
"����һ���ܳ��ܳ��Ĺ��£�����\n",
"�ھ�����һ�꣬�ҳ���һ���¶���������£����Ѿ��ǲ����ˡ�\n",
"��ʱ��������ʱ�ڡ�����Ķ����ر��䣬ѩ��ѹ���˼��ϳ�����������ɡ�\n",
"����żȻ�����Ľ����������ң�������һ����Ӧ�ڼ�����������ȥ�Ĺ»ꡣ\n",
"�������Ҵ��ش�����̣�������������ң�������������֮����\n",
"���ڶ�ʮ�����Ϊ��¥����֮ǰ����ʮ���꣬Ҳ��������������ֵ�ʮ���ꡣ\n",
"Ȼ������һ�꣮������һ�궬�죬������֪���������µ���ŮԬ�������ȴ��������˹��Ʒɡ�\n",
"������飬�����������в�֪��ȴ�������ű���������ҡ�\n",
"������������ң���æ�ϻؽ���֮ʱ������ѩ�価����ɢȥ������\n",
"���ϵĶ���Ī��ĺޣ����������븴Թ�Ľ�֯����������¥�����������λ�ϣ���������ɱ����\n",
"�ұ���Ϊ�������ֻ�ǧ��Ҳ�޷�ĥ�����������飬��������������ĥ�ң�����\n",
"ֱ�����ڣ�����ȥ֮ǰ�������ڷ����Լ��������ִ����\n",
"��Щ����ֻ�������ض���ʱ���ڣ������Ƕ�ʱ���û�������ڵ������ˡ�\n",
"�ڼ��������õĶ�����������ֻ�����ڼ����аɡ�\n",
"������ˣ�лл�㣬�����ڿ��Խ��ѡ�\n\n"});

        msg = event_msg[count];
        message_vision(WHT+msg+NOR,me,target);
        if (count < 17)
                call_out("do_exc",1+random(2),me,target,count+1);
        else
        {
                target->start_busy(1);
                target->set("annie/demon_killed_du",1);
                ::die();
        }
        return;

}

