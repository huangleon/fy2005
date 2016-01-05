inherit NPC;
#include <ansi.h>
#include <combat.h>

void smart_fight();
string do_flee();

void create()
{
		object weapon;
        set_name("�˺�ʦ̫", ({ "liaohen"}) );
	    set("title",YEL"ˮ��������"NOR);
		set("nickname",MAG"�������������"NOR);
        set("gender", "Ů��" );
		
		set("class","shaolin");
    	set("long", "һλ�����ذ�ɮ�۵����ᣬ������������֮�ϣ������\n");

		set("no_arrest",1);

		set("chat_chance", 1);
		set("chat_msg", ({
				"�˺�ʦ̫΢΢һЦ��\n",
				"�˺�ʦ̫���������ģ���Ⱦ���������ֻؽ�ΪԵ������Ե��ԵΪ�ģ�������Ե���޺ۡ�\n",
				"�˺�ʦ̫����ɽ��������Թ�ֻ꣬�޽��յ�·���������ܳ���ǰ�С�\n",
		}) );

        set("inquiry",([
 		"����"  :"������Թ��Ӧ���Ƽ��������У���ֻ�轫�䴦���������ǡ�\n�˺�ʦ̫����һ�٣��ֵ����ǹȸ���������ʢ��ֻ�»���ʲôа���������磬���Լ����С�ġ�\n",
 		"Թ��"  :"������Թ��Ӧ���Ƽ��������У���ֻ�轫�䴦���������ǡ�\n�˺�ʦ̫����һ�٣��ֵ����ǹȸ���������ʢ��ֻ�»���ʲôа���������磬���Լ����С�ġ�\n",
 		"ɽ��"  :"������С��ֱ�߱��ǣ�������ǰһ��������������ʯ������·��٣�����������������\n",
              ]) );

        set("age", 54);

        set("attitude","friendly");
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
//                (: smart_fight() :),
                (: ccommand("chant") :),
        }) );

        set("combat_exp", 5200000);
    
        set_skill("chanting", 150);
		set_skill("zen",250);
		set_skill("lamaism",250);
		set_skill("buddhism",250);
        
		set("skill_public",1);
        
		setup();

	carry_object("/obj/armor/cloth",([	"name": "������",
    						"long": "һ��ϴ�÷��׵�ɮ�ۡ�\n",
    						"value": 1,
    						 ]))->wear();    
	carry_object("/obj/armor/necklace",([	"name": MAG"�������"NOR,
    						"long": "һ������������ɵľ�����\n",
    						"value": 1,
    						 ]))->wear();    
}


int recognize_apprentice(object ob)
{
	if (REWARD_D->riddle_check(ob,"��������/ս��ʬ"))
		if (REWARD_D->riddle_check(ob,"��������/�ظ�"))
			if (REWARD_D->riddle_check(ob,"��������/ʳ��"))
				if (REWARD_D->riddle_check(ob,"��������/Ѫ��"))
				{
					message_vision("\n�˺�ʦ̫���ŷ��飬����������ӷ����գ����ա�\n\n",ob);
					REWARD_D->riddle_done(ob,"��������",20,1);
					ob->set("free_learn/chanting",1);
				}

	if (!ob->query("free_learn/chanting"))
	{
		message_vision("�˺�ʦ̫����ҵ��δ������ˡ���������ڷ�������\n\n",ob);
		return 0;
	}
    return 1;
}


int kill_ob(object who)
{
	ccommand("emote ����������ӷ𣮣���");
	ccommand("emote ��������վ��������");
	::kill_ob(who);
	return 1;
}



int prevent_learn(object me, string skill)
{
  if (skill != "chanting")
  {
      command("shake");
      command("say ����ѧ�����ģ�ֻ���������Լ��Ķ���");
      return 1;
  }
  return 0;
}

int prevent_shown(object me, string skill)
{
	if (skill == "chanting")
		return 0;
	
	return 1;
}

/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/

