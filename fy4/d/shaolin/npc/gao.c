// ; annie 07.2003
// dancing_faery@hotmail.com
// 
// �˲���֮�������� �������� ���� 
// EXP 8M KEE 80K GIN/SEN 60K RESIST/ALL 50
// STR 95 DMG 988 ATTACK 752K DODGE 730K PARRY 490K
// ����Ӱ(4x)��Counter-Attack����С����PERFORM YAOZHAN(almost 1hit gone)��

// A/D/P����׼8M״̬��

inherit NPC;
#include <ansi.h>
#include <combat.h>
void smart_fight(object who);

void create()
{
	object armor,weapon;
	set_name("����", ({ "gao meng","gao"}) );
	set("gender", "����" );
	set("title",YEL"������� "NOR CYN"��������"NOR);
	set("nickname",HIY"��������"NOR);
	set("age", 30+random(10));

	set("attitude","friendly");

	set("long",
		"����ԭ��������ʿ�����Զ�孵���������Ϊ��Ѱ�������ߵ�һ\n������ӡ��������ԭ��ȴ��̤�϶���֮���������ԭ��ѧ�Ĳ���\n����Ĵ���Ͷ���ɶ��������ڡ��˺���������ԭ��ʧ������Ҳ\n���������������·�������δ�����֣�Ȼ��ȴû����֪��������\n�ҵ�Ψһ�Ͻ���������������ħ�̡�\n"
		);
	set("class","demon");
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

	set("chat_chance", 1);
        set("chat_msg", ({
                "���ʹ����������ϵ����֣�������ͷ���������˱�������Ȼ�����鴫��\n",
                "���ͺٺ���Ц����ֻ�Ǻ��˲�˼�������ų��켺���̲��Է�ı��£�Ҳ�������鴫��\n",
                "������ü˼��������"YEL"�������Ϲ���"NOR"�����������������ʩչ�Ļ�������\n",
                "���;��ȵĿ�����һ�ۣ��׵�������˭����ô������ͭ����\n",
                "���Ͷ����д��˿�����̾������ƽ�߼ҵ��常��Ҳ���Ҹ�ʱ��ȥ̽��һ���ˡ�\n",
                }) );

    set("inquiry", ([
        "�������Ϲ���": "�����������������Ϲ����������Ҷ�������������޵С�",
        "xingyi stick": "�����������������Ϲ����������Ҷ�������������޵С�",
        "xingyi-stick": "�����������������Ϲ����������Ҷ�������������޵С�",
        "������":   "���ֺ��У��书�ã����۲��á�",
        "����":   "���ֺ��У��书�ã����۲��á�",
        "shaolin":   "���ֺ��У��书�ã����۲��á�",
        "����":   "action����ҡҡͷ������Ҫ�ʣ���Ҫ�ʡ�",
        "ħ��":   "action����ҡҡͷ������Ҫ�ʣ���Ҫ�ʡ�",
        "demon":   "action����ҡҡͷ������Ҫ�ʣ���Ҫ�ʡ�",
        "�������":   "action����ҡҡͷ������Ҫ�ʣ���Ҫ�ʡ�",
        "�������":   "action����ҡҡͷ������Ҫ�ʣ���Ҫ�ʡ�",
        "������":   "���ֺ��У��书�ã����۲��ã����������䲻�á�\n������˵������������ȻԸ����ң��ҾͲ�˵�����ﲻ�á�",
        "��":   "���ֺ��У��书�ã����۲��ã����������䲻�á�\n������˵������������ȻԸ����ң��ҾͲ�˵�����ﲻ�á�",
        "�ݰ�":   "���ֺ��У��书�ã����۲��ã����������䲻�á�\n������˵������������ȻԸ����ң��ҾͲ�˵�����ﲻ�á�",
        "bai":   "���ֺ��У��书�ã����۲��ã����������䲻�á�\n������˵������������ȻԸ����ң��ҾͲ�˵�����ﲻ�á�",
        "����":   "��������Ӧ�Ѿ�����ң���ô�����ڻ�û����",
        "book":   "��������Ӧ�Ѿ�����ң���ô�����ڻ�û����",
        "������":   "��������Ӧ�Ѿ�����ң���ô�����ڻ�û����",
        "��":   "����ʲô�����Ҳ�֪����",
        "thief":   "����ʲô�����Ҳ�֪����",
         ]) );

		
	set("resistance/gin",50);
	set("resistance/kee",50);
	set("resistance/sen",50);

	set("max_kee",80000);
	set("max_gin",60000);
	set("max_sen",60000);
	
	set_skill("demon-blade",200);
	set_skill("blade",200);

	set_skill("demon-steps",200);
	set_skill("fall-steps",200);
	set_skill("anxiang-steps",200);
	set_skill("cloud-dance",280);
	set_skill("move",200);
	set_skill("dodge",200);

    set_skill("perception",200);
    set_skill("stormdance",320);

	set_skill("meihua-shou",210);
  	set_skill("unarmed", 400);
	set_skill("force", 200);

	set_skill("kongshoudao", 400);
	set_skill("lingxi-zhi", 170);
	set_skill("spells",200);
	set_skill("parry",200);
	set_skill("kwan-yin-spells",200);
	set_skill("five-steps",180);
	set_skill("move",200);
	set_skill("dodge",200);
	
	map_skill("spells","kwan-yin-spells");
	map_skill("parry", "lingxi-zhi");
	map_skill("unarmed", "kongshoudao");
	map_skill("force", "bolomiduo");
    	map_skill("dodge","cloud-dance");
    	map_skill("move","stormdance");
    	map_skill("blade","demon-blade");
    	
        add_temp("apply/iron-cloth", 200);
	
	
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight(this_object()) :),
        }) );


	setup();
	set_temp("counter_action_extra",1);
	set_temp("counter_msg",CYN"$N��׼������ٿȻһԾ���������ַ�����\n"NOR);

	carry_object(__DIR__"obj/gaoarmor")->wear();
	carry_object(__DIR__"obj/paper1");
}

int kill_ob(object who)
{
	object me,mirrorimage;
	int i,j;
	message_vision(HIY"������Цһ��������һ�Σ�����һģһ�����ĸ���Ӱ��\n\n"NOR,this_object());
	i = random(4);
	for (j=0;j<4;j++)
	{
		mirrorimage = new(__DIR__"gao_mirrorimage");
		if (i == j)
		{
		    mirrorimage->set("reward_npc", 1);
			mirrorimage->set("difficulty",7);
		}
		mirrorimage->move(environment());
		mirrorimage->set("eff_gin",query("eff_gin"));
		mirrorimage->set("eff_kee",query("eff_kee"));
		mirrorimage->set("eff_sen",query("eff_sen"));
		mirrorimage->set("gin",query("gin"));
		mirrorimage->set("kee",query("kee"));
		mirrorimage->set("sen",query("sen"));
		mirrorimage->kill_ob(who);
		who->kill_ob(mirrorimage);
	}
	destruct(this_object());
	return 1;
}

void dispel_mi()
{
	int i;
	object mi;
	for (i=0;i<4 ; i++)
	{
		mi=present("mirror image",environment());
		if (mi)
			destruct(mi);
	}
	return;
}

void rebuild_images(object * enemy)
{
	object me,mirrorimage;
	int i,j,k;
	dispel_mi();
	message_vision(HIY"���ͳ���һ��������������չ���������ػ�Ӱ��\n\n"NOR,this_object());
//	ccommand("say "+sizeof(enemy)); 	// debug,by annie 07.2003
	i = random(4);
	for (j=0;j<4;j++)
	{
		mirrorimage = new(__DIR__"gao_mirrorimage");
		if (i == j)
		{
		    mirrorimage->set("reward_npc", 1);
			mirrorimage->set("difficulty",7);

			// dispel but copy GKS
			mirrorimage->set("eff_gin",query("eff_gin"));
			mirrorimage->set("eff_kee",query("eff_kee"));
			mirrorimage->set("eff_sen",query("eff_sen"));
			mirrorimage->set("gin",query("gin"));
			mirrorimage->set("kee",query("kee"));
			mirrorimage->set("sen",query("sen"));
		}
		mirrorimage->move(environment());
		for (k=0; k<sizeof(enemy); k++)
		{
/*			ccommand("say k="+k);
			ccommand("say enemy[k]="+enemy[k]->name());
			ccommand("say 123");*/	// debug,by annie 07.2003
			mirrorimage->kill_ob(enemy[k]);
			enemy[k]->kill_ob(mirrorimage);
		}
	}
	destruct(this_object());
	return;
}

