
inherit NPC;
#include <ansi.h>
#include <combat.h>
void smart_fight(object who);

void create()
{
	object armor,weapon;
	set_name("ˮ����", ({ "shui ruxi","shui"}) );
	set("gender", "Ů��" );
	set("title",WHT"������Ů"NOR);
	set("nickname",HIW"���ﻨ��"NOR);
	set("age", 20+random(10));

	set("attitude","friendly");

	set("long",
		"������������������������ϣ�һ��ˮ��ɫ���ɴ��ȹ���ҷ�\n�����䷭�ɣ����ŵ��Ϸ����Ĵ�����˿���ڷ���Ʈ�費������\n�ܱ������㣬��ò�Ѽ������������һ�ۼ�����Ϊ�Ǵ�׹����\n�����ӣ��˿������˷��ȥ��\n"
		);
	set("class","demon");
    set("combat_exp", 0);	
    set("score", 10000);
	set("fle",50);
	set("cor",40);
	set("cps",30);
	set("str",20);
	set("per",200);
	set("force",2500);
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
                "ˮ��������һ�ߣ�˵�����䵱����������������ʧ��������ʲô�䵱��\n",
                "ˮ����ҡҡͷ����ʯ�����£������ݰ�������\n",
                "ˮ����̾��������һ���ˣ���֪�������������Ǳ߹�����Σ�����\n",
                "ˮ�������׿��������У���������⻹���ϴξ͸�����������ģ�ʲôʱ����п���ȥ�أ�\n",
                }) );
			

    set("inquiry", ([
        "̫���ķ�": "��Ц�䵱������ȥ��̫���ķ��н����������ľ���\n��ʧ������ȥ�Ұ���ʱ�䷽��������ؼ����ҵ���",
        "�䵱��":   "��Ц�䵱������ȥ��̫���ķ��н����������ľ���\n��ʧ������ȥ�Ұ���ʱ�䷽��������ؼ����ҵ���",
        "�䵱":   "��Ц�䵱������ȥ��̫���ķ��н����������ľ���\n��ʧ������ȥ�Ұ���ʱ�䷽��������ؼ����ҵ���",
        "����":   "actionˮ�����������߷�˿���ƺ�û���������������",
        "ħ��":   "actionˮ�����������߷�˿���ƺ�û���������������",
        "�������":   "actionˮ�����������߷�˿���ƺ�û���������������",
        "�������":   "actionˮ�����������߷�˿���ƺ�û���������������",
        "�ݰ�":   "actionˮ��������һЦ�����׹˵���Ʃ���㣬���Ǹ���ݰ���",
        "��ݰ�":   "actionˮ��������һЦ�����׹˵���Ʃ���㣬���Ǹ���ݰ���",
        "ʯ��":   "˵ʲô�������ˣ������Ǻ�����Щ����һ����ݰ���������ϧ��",
        "�䵱������":   "�����ŵ�Ҳ���飬�������ǲݰ�ʯ��������ϣ�\n��ȡ�����䵱�ɻ�Ҫ��Щ�����鷳��\nˮ����ƲƲ�������������ʯ�������ĵ��ӣ�Ҳ�Ͳ���������\nʶ�˲��壬�������ң��Ծ�����������Ҳ��ԩ�ˡ�",
        "������":   "�����ŵ�Ҳ���飬�������ǲݰ�ʯ��������ϣ�\n��ȡ�����䵱�ɻ�Ҫ��Щ�����鷳��\nˮ����ƲƲ�������������ʯ�������ĵ��ӣ�Ҳ�Ͳ���������\nʶ�˲��壬�������ң��Ծ�����������Ҳ��ԩ�ˡ�",
        "�ϵ�����":   "����ֻ�����Ǿ���һ�����ӣ�����С�䣬��ֵһ�ᡣ",
        "ľ����":   "����ֻ�����Ǿ���һ�����ӣ�����С�䣬��ֵһ�ᡣ",
         ]) );

		add_temp("apply/iron-cloth", 200);
	
		set("NO_KILL","��˽������˵�Ů�ӣ����������̵��������֣�\n");
	
	setup();

	carry_object(__DIR__"obj/longskirt")->wear();
}

int accept_object(object who, object ob)
{


	if (ob->query("name")==CYN"��������"NOR 
		&& ob->query("id") == "cyan needle" 
		&& REWARD_D->check_m_success(who,"�䵱����"))
	{
		command("giggle shui ruxi");
		command("emote ������Ц�����㾹Ȼ�ҵõ��ҡ�");
		command("fox");
		command("say �Ǻðɣ��������ҵ���һɲ��\n");
		remove_call_out("greeting");
		call_out("greeting", 1,who);

		return 1;
	}
	return 0;
}


void greeting(object ob)
{
	message_vision(HIC"\n����ǰһ������������Ů���Ѳ�֪�Ӻδ��ճ�һ��ǳ��ɫ�Ķ̵���\n"NOR,ob);
	message_vision(HIW"\nˮ������Ŀ���⣬��Ц�����������֪����ɱ��ʯ�㣬�ִ���Σ�\n\n"NOR,ob);
	ob = new(__DIR__"shui");
	ob->move(environment());
    if (environment())
		environment()->set("boss_out",time());
	destruct(this_object());
}