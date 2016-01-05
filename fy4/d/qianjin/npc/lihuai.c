inherit NPC;
#include <ansi.h>
void create()
{
        object weapon;
        set_name("�", ({ "li huai","li" }) );
        set("gender", "����" );
                set("nickname",HIG"�ּ��ɵ�"NOR);
                set("age",20);
        set("reward_npc", 1);
                set("difficulty", 10);
                set("attitude","friendly");
        set("max_force", 15000);
        set("force", 15000);
        set("force_factor", 1);
        set("long","һ���糾���͵������ˣ���һ������˵����ѣ�\n��������Ӧ���ޱ����ǣ�����ȴ���ޱȾ���\n");
        create_family("����һ��", 4, "�˽�");
        set("combat_exp", 10000000);

        set("chat_chance", 1);
        set("chat_msg", ({
                "��������ƣ��ҵ�����Ӧ�ý����ƣ�������ô�����ˣ��������ҲӦ�ý����\n",
                "�Ц�������ֽ�����ˣ�����һ����ľ��ǻ��ˡ�\n",
                "�������һ�ۣ�ͻȻ̧�ֳ��˼���"YEL"����"NOR"��\n",
                "�������ͻȻ���������翣����Ƶ�̾��������ľ���ô�����ˣ���ģ�����\n",
        }) );
        set_skill("move", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("throwing", 300);
                set_skill("feidao", 220);
        set_skill("force", 40);
        set_skill("literate", 200);
        map_skill("throwing", "feidao");
        setup();
        weapon = carry_object("/obj/armor/cloth");
                weapon->set("name",HIR BLK"�����˵�����"NOR);
                weapon->wear();
        weapon=carry_object("/questnpc/obj/leaf");
        weapon->set_name(YEL"����"NOR, ({ "tofu" }) );
                weapon->set("long","һ�����ۻ����Ķ�������ʵ�ڲ���������Ҳ��һ��������\n");
                weapon->set("base_unit","��");
                weapon->set("value",0);
                weapon->set_amount(200);
                weapon->set("volumn",200);
                weapon->wield();
}

int do_look(string arg)
{
        if (!arg)
                return 0;
        if (present(arg,environment()) != this_object())
                return 0;
        write("һ���糾���͵������ˣ���һ������˵����ѣ�\n��������Ӧ���ޱ����ǣ�����ȴ���ޱȾ���\n��������Լ��ʮ���ꡣ\n��������棬�������ٷ硣\n��"CYN"���˾�����������"GRN"���书����������"HIB"�����ž�"NOR"�������ƺ����ᡣ\n��"HIG"�������ϲ���˿���˺ۡ�"NOR"\n����������һ��"YEL"����"NOR"(Tofu)\n  ��"HIR BLK"�����˵�����"NOR"(Cloth)\n");
        return 1;
}

void init()
{
        add_action("do_look","look");
        ::init();
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
                if (userp(enemy[i]) && enemy[i]->query("annie/moon_master") != 4)
                        return enemy[i]; // focus user. ; annie 6.25.03
        
        return enemy[random(sizeof(enemy))];
}

void heart_beat()
{
        object feidao;
        object target;
        if(is_fighting())
        {
                target = select_opponent();
                        message_vision(CYN"\n�����һ����Ƿ���������ļ��ˡ�\n\n"NOR,this_object());
                        feidao = new(AREA_FY"npc/obj/xlfd_knife");
                        feidao->move(this_object());
                        command("unwield deadleaf");
                        command("wield flying blade");
                        target->set_temp("last_damage_from",this_object());
                        (CLASS_D("npc") + "/feidao/xiaoli-feidao")->kill_him(this_object(),target);
                        feidao->throw_weapon(this_object(),target,0);
                        if (feidao)
                        {
                                feidao->unwield();
                                feidao->move(load_object("/obj/void"));
                                reset_action();
                        }
                        command("wield deadleaf");
                        command("hehe");
                return ::heart_beat();
        }
        else
                return ::heart_beat();
}


int accept_object(object me, object obj)
{
        if (obj->query("name") == "Сֽ��" && obj->query("real") == 3)
        {
                if (REWARD_D->riddle_check(me,"������Թ") == 9 )
                {
                        message_vision(CYN"���Сֽ�������������еķ�ĩ��\n"NOR,me);
                        message_vision(CYN"�ĬȻ���Σ�����̾�˿�����\n"NOR,me);
                        ccommand("say ����������");
                        ccommand("sigh");
                        ccommand("emote ���˵�ͷ����������ˣ������һ�ܣ��������������ǷѦ�ҵ�ԩԹ��");
                        ccommand("say ���ȥ�������ذɣ����´�����ӯ�յ�ʱ�������ϵط�������");
                       	REWARD_D->riddle_set(me,"������Թ",10);

                        message_vision(CYN"��������߻ط�԰�С�\n"NOR,me);
                        move(load_object("/d/wiz/deathroom"));
                        return 1;
                }
        }
        command("smile");
        command("say ��л����л��");
        return 1;
}


/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/

