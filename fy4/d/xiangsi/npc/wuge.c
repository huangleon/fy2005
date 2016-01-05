// annie 07.2003
// dancing_faery@hotmail.com

// *lazy blanche

#include <ansi.h>
#include <combat.h>
inherit NPC;
int blade_book();
int starrain_book();
int spells_book();

void create()
{
	set_name("Ѧ�޸�", ({ "xue wuge", "wuge","xue" }) );
	set("class","moon");
	set("gender", "����" );
	set("age", 25);

	set("nickname",HIY"��񲻸�����ʱ"NOR);
	set("title","��¹�"NOR);
	set("attitude", "friendly");

	set("long","������˼��˫Ŀ΢�գ���һ��������ͦ�����������ܲص��ػ�֮�ˡ�\n�������Ҫʲô�鼮��������������������\n");

	set("no_arrest",1);
	set("inquiry",([

       	"����": 	"�ؽ�㣿������ȥ�ˡ�\n",
       	"�": 	"��������ǰ���Ǹ����ı���֮ͽ��\n",

		"recent": 	"�������ף������������Ǻ��ݺᣬ������ı���\n",
       	"recent book": 	"�������ף������������Ǻ��ݺᣬ������ı���\n",
       	"book": 	"�������ף������������Ǻ��ݺᣬ������ı���\n",
       	"��": 	"�������ף������������Ǻ��ݺᣬ������ı���\n",
       	"�鼮": 	"�������ף������������Ǻ��ݺᣬ������ı���\n",
       	"����": 	"�������ף������������Ǻ��ݺᣬ������ı���\n",
		"��������" : 	(: blade_book :),
		"��������" : 	(: spells_book :),
		"�Ǻ��ݺ�" : 	(: starrain_book :),
    	]) );


	set("combat_exp", 3600000);

	set_skill("starrain", 180);
	set_skill("throwing", 200);
	map_skill("throwing","starrain");

	set_skill("force", 200);
	set_skill("snowforce", 200);
	map_skill("force","snowforce");

	set_skill("dodge", 200);
	set_skill("move", 200);
	
	set_skill("stormdance", 150);
	map_skill("dodge","stormdance");
	map_skill("move","stormdance");
	map_skill("parry", "starrain");
	
	set_skill("unarmed",200);
	set_skill("lingxi-zhi",200);
	map_skill("unarmed","lingxi-zhi");

	setup();

	carry_object(__DIR__"obj/ccloth")->wear();
	carry_object(__DIR__"obj/feidao")->wield();

}


int blade_book()
{
	object me = this_player(),book;
   /*   if (!query("bladebook") || me->query("class") != "moon")
	{
		message_vision(CYN"$N˵������Ǹ�����Ѿ����˽����ˡ�\n"NOR,this_object());
		return 1;
	}                    */   //add by ldb           һֱ�ܽ� 
	if (me->query("annie/moon_borrowbook"))
	{
		message_vision(CYN"$N����Ŀ���$nһ�ۣ�˵�������ϴν��ߵ��飬��û�л���\n"NOR,this_object(),me);
		return 1;
	}    
	ccommand("ok");
	book = new("/obj/book/blade_51");
	message_vision(CYN"$N���������ѲƬ�̣����һ���鼮�ݸ�$n��\n"NOR,this_object(),me);
	if (book->move(me))
	{
		add("bladebook",-1);
		message_vision(CYN"$N˵���������ˣ��ǵû�����\n"NOR,this_object(),me);
		me->set("annie/moon_borrowbook",1);
	}
	else
	{
		message_vision(CYN"$Nһ������$n��ƨƨ�ϣ�ӡ��һ�������Ьӡ��\n"NOR,this_object(),me);
		message_vision(CYN"$N˵������ȥ�����������������顣\n"NOR,this_object(),me);
		destruct(book);
	}
	
	return 1;	
}

int spells_book()
{
	object me = this_player(),book;
    /*	if (!query("spellsbook") || me->query("class") != "moon")
	{
		message_vision(CYN"$N˵������Ǹ�����Ѿ����˽����ˡ�\n"NOR,this_object());
		return 1;
	}                     */        //add by ldb           һֱ�ܽ� 
	if (me->query("annie/moon_borrowbook"))
	{
		message_vision(CYN"$N����Ŀ���$nһ�ۣ�˵�������ϴν��ߵ��飬��û�л���\n"NOR,this_object(),me);
		return 1;
	}
	ccommand("ok");
	book = new("/obj/book/spells_51");
	message_vision(CYN"$N���������ѲƬ�̣����һ���鼮�ݸ�$n��\n"NOR,this_object(),me);
	if (book->move(me))
	{
		add("spellsbook",-1);
		message_vision(CYN"$N˵���������ˣ��ǵû�����\n"NOR,this_object(),me);
		me->set("annie/moon_borrowbook",1);
	}
	else
	{
		message_vision(CYN"$Nһ������$n��ƨƨ�ϣ�ӡ��һ�������Ьӡ��\n"NOR,this_object(),me);
		message_vision(CYN"$N˵������ȥ�����������������顣\n"NOR,this_object(),me);
		destruct(book);
	}
	
	return 1;	
}

int starrain_book()
{
	object me = this_player(),book;
   	if (!query("starrain") || me->query("class") != "moon")
	{
		message_vision(CYN"$N˵������Ǹ�����Ѿ����˽����ˡ�\n"NOR,this_object());
		return 1;
	}                                       
	if (me->query("annie/moon_borrowbook"))
	{
		message_vision(CYN"$N����Ŀ���$nһ�ۣ�˵�������ϴν��ߵ��飬��û�л���\n"NOR,this_object(),me);
		return 1;
	}
	ccommand("ok");
	book = new(__DIR__"obj/starrain");
	message_vision(CYN"$N���������ѲƬ�̣����һ���鼮�ݸ�$n��\n"NOR,this_object(),me);
	if (book->move(me))
	{
		add("starrain",-1);
		message_vision(CYN"$N˵���������ˣ��ǵû�����\n"NOR,this_object(),me);
		me->set("annie/moon_borrowbook",1);
	}
	else
	{
		message_vision(CYN"$Nһ������$n��ƨƨ�ϣ�ӡ��һ�������Ьӡ��\n"NOR,this_object(),me);
		message_vision(CYN"$N˵������ȥ�����������������顣\n"NOR,this_object(),me);
		destruct(book);
	}
	
	return 1;	
}


int accept_object(object who, object ob)
{
	if(ob->query("skill/name") == "blade" && ob->name() == "��������")
	{
		if (!who->query("annie/moon_borrowbook"))
		{
			ccommand("hmm "+who->query("id"));
			message_vision(CYN"$N�ʵ����Ȿ��������������\n"NOR,this_object(),who);
		}
		else
		{
			ccommand("pat "+who->query("id"));
			ccommand("say �н��л����ٽ費�ѡ�");
			ccommand("smile "+who->query("id"));
			who->delete("annie/moon_borrowbook");
		}
		return 1;
	}
	if(ob->query("skill/name") == "spells" && ob->name() == "��������")
	{
		if (!who->query("annie/moon_borrowbook"))
		{
			ccommand("hmm "+who->query("id"));
			message_vision(CYN"$N�ʵ����Ȿ��������������\n"NOR,this_object(),who);
		}
		else
		{
			ccommand("pat "+who->query("id"));
			ccommand("say �н��л����ٽ費�ѡ�");
			ccommand("smile "+who->query("id"));
			who->delete("annie/moon_borrowbook");
		}
		return 1;
	}
	if(ob->query("skill/name") == "starrain" && ob->name() == "�Ǻ��ݺ�")
	{
		if (!who->query("annie/moon_borrowbook"))
		{
			ccommand("hmm "+who->query("id"));
			message_vision(CYN"$N�ʵ����Ȿ��������������\n"NOR,this_object(),who);
		}
		else
		{
			ccommand("pat "+who->query("id"));
			ccommand("say �н��л����ٽ費�ѡ�");
			ccommand("smile "+who->query("id"));
			who->delete("annie/moon_borrowbook");
		}
		return 1;
	}
	return 0;
}


void killed_enemy(object who)
{
	message_vision(CYN"Ѧ�޸��$Nҡͷ̾������ʵ����������׻ӻ���Ҳ���Լ���ƽʵ��\nҪ���Ρ������룬���ӾͿ��Թ����������á�����ʵ�ڲ������ġ�"NOR,who);
}

