// beggar.c

inherit NPC;
#include <ansi.h>
int answer_snake();
void create()
{
        set_name("ˣ����ؤ", ({ "playsnake beggar" }) );
        set("gender", "����" );
        set("age", 53);
        set("long", 
"����һ�������Ĵ���å���գ�ˣ������Ϊ����������ؤ���������¶��ߵ��ŵ� 
��˵��ʮ�־�ͨ�� \n");
        set("combat_exp", 10000);
        set("str", 30);
        set("force", 500);
        set("max_force", 500);
        set("force_factor", 5);
        set("chat_chance", 2);
		
        set("chat_msg", ({
        "ˣ����ؤ˫�۲����Ÿ�ʽ�������ٺ���Ц�ſ��Ź������ˡ�\n",
        "ˣ����ؤ����ߺ���ţ���һ������һ�ư��������䶾�����ߵ���
�Ǳ�����ר�ξ�֢�ϡ�\n",   
        }) );
		set("inquiry",([
			"����" : (:answer_snake:),
			"��" : (:answer_snake:),
			"snake" : (:answer_snake:),
			]) );
        setup();
    carry_object("obj/armor/cloth")->wear();
}

int accept_object(object me, object obj)
{
		object snake;
		if (obj->query("money_id") == "gold" && obj->query_amount() >=10)
		{
			message_vision(
YEL"$N��׵����ã���Ȼ"+RANK_D->query_respect(me)+"��˿�������Ҳ����˽�ˣ�������
�����ߣ�һΪ��β�ߣ�һΪ��Ҷ�ߣ�����һ������ȴ���ر���Ѱ��������ү�����ã��� 
������һ�����������ү���ǻر��ɣ� \n"NOR,this_object());
			message_vision("\n$N�ӱ��в�����ų�����ɫС�ߣ��ٺ���Ц��һ����\n",this_object());
			snake = new(__DIR__"wangsnake");
			snake->move(environment(this_object()));
			snake->kill_ob(me);
		}else
		{
			command("smile");
			command("say ��л��λ" + RANK_D->query_respect(me) + 
	"��������һ�����кñ��ģ�");
		}
        return 1;
}

int answer_snake()
{
	object me;
	me = this_player();
	message_vision(
YEL"$N����б�ۿ��˿�$n������������˶������߶�������ô����ѯ�� 
�������ˣ������֡��ٺ٣����������Ĵ����Ļ����ܵ���˼��˼�ɣ� \n"NOR,this_object(),me);
	return 1;
}
 
