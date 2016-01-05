#include <ansi.h>
inherit NPC;

void create()
{
		set_name("���", ({ "li e","e","li" }) );
        set("gender", "����" );
        set("age", 44);
		set("title","����");
		set("combat_exp", 8000000);

		set("skill_public",1);

        set("attitude", "friendly");
		set_skill("unarmed", 120);
        set_skill("ironcuff", 200);

        set("chat_chance", 1);
        set("chat_msg", ({
        "���̤�ڶ��裺����������ò�࣬��ˮ�����Ѷ�����ƽ������ƽ���ͣ��糤�������ɹء�\n",
        "���Ц����������ƽ����ȭ����Խѧ��ͻᷢ��Խ�Ǽ��ѡ�\n",
        }) );
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: ccommand("perform heihutaoxin") :),
             }) );
		set("busy_immune",4);
		map_skill("unarmed","ironcuff");
        setup();
}



int prevent_learn(object me, string skill)
{
  if (skill != "ironcuff")
  {
      command("shake");
      command("say ������Ҫ���Լ�ȥ�򣬴������������ѧȭ����");
      return 1;
  }
  return 0;
}

int prevent_shown(object me, string skill)
{
	if (skill == "ironcuff")
		return 0;
	
	return 1;
}

int recognize_apprentice(object ob)
{
	if (ob->query("class") || ob->query("once_menpai"))
	{
		message_vision("���������Ц���������ʦ���ֺα�����һ�����ָ�㣿\n",ob);
		return 0;
	}
	if (!ob->query("free_learn/ironcuff"))
	{
		ob->set("free_learn/ironcuff",1);
		message_vision(CYN"���Ц�������۹⡣\n\n",ob);
		message_vision("�����������һ����ɽ��ȭ���ս��ľ���������֮���׵���ʽ���Ȳ����ɣ�Ҳ���ÿ���\n",ob);
		message_vision("Ȼ������֮���Գ�Ϊ���У�������Ϊ���ã����Գ���Ҫ�ã��ö��˴�Ҷ��ᣬ��˶���ϣ�档\n",ob);
		message_vision("��ѧ��ʦ���޲����Դ��书��������ʽ����׷�����ɣ������˷��ӹ���ı��⡣\n",ob);
		message_vision("����ν��ǿ����ǿ������ɽ�ڣ����������ᣬ�����մ󽭣��浽��ս��֮�ϣ�ʲô������Ҳ����ȥ�ܣ�\n",ob);
		message_vision("ֻҪ����ʵʵ��һ��һʽ������ɽ��ȭ��������ɵ�������æ���ҡ�\n\n",ob);
		message_vision("���ͣ��һͣ���ֵ�����֪ѧ�����ģ���ѧ����ͷҲ�������٣���֪�Լ��Ѿ�����������ˡ�\n"NOR,ob);
	}
    return 1;
}

