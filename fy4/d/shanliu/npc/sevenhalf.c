// yangfan.c

inherit NPC;

#include <ansi.h>
void create()
{
        set_name("�߸���",  ({  "wineseller"  }) );
	set("title","ţ������ �ϰ�");
        set("gender", "����" );
	set("age", 50);
	set("long",
"��������ϰ壬��Ϊ��ʲô��ֻ���߸���ͭ�壬���Ա㱻�˳����߸��룬����ȥ
�Ǹ�����ֵ��ˣ���Ȼ����Щȳ��ͷҲ��Щͺ������Ҳ�ܴ��ף��书����ȥҲ��
������ȥ���������йɽ������������Ⱦƣ����������ζ����\n");
        set("chat_chance", 1);
        set("chat_msg", ({
            "�߸������������ذ����һ�ڣ����������͹ٳ�Щʲô��\n",
    }) );
	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("per",1);
	set("str", 100);
	set("force",5000);
	set("max_force",5000);
	set("force_factor",500);
	set_skill("dodge",300);
        set_skill("unarmed",200);
        set_skill("parry", 200);
        set_skill("changquan", 200);
        set_skill("fall-steps", 200);
        map_skill("unarmed", "changquan");
        map_skill("dodge", "fall-steps");
	setup();
        carry_object("obj/armor/cloth")->wear();

}

int accept_object(object me,object ob)
{
	if(ob->query("id")!="letter" && ob->query("id") != "tanmubox") return 0;
	if (ob->query("�Ͷ�����") != me)
	{
		message_vision("$N�ӹ����������˿�����$n��Ц���������������Ķ��������Һ�Ū�ҡ�\n",this_object(),me);
		kill_ob(me);
		return 1;
	}
	if (ob->query("open"))
	{
		message_vision(
HIC"$NƲ��$nһ�ۣ�����ĵ�����Ե�����ˣ���̨���ǻ�ͷ�ǰ��ɡ���\n"NOR,this_object(),me);
		me->delete_temp("ɽ��/�Ͷ���");
		return 1;
	}
	if(ob->query("name")=="���߸������")
	{
		if (me->query_temp("givebox"))
		{
			
			message_vision(
HIW"$N���ţ����˰��Σ����������´�����$nһ��������Ц��������Ȼ�Ǻ��ֵܣ�
�ðɣ�����ǰ�ߣ��и������£���ɽ�и��������µĵط������ĵĻ����Ǿ�����ȥ�ɣ���
���������ɽ�����Ϳ�Ե���ˡ�\n"NOR,this_object(),me);
			tell_object(me,"�ƿ����Ӻ������(open curtain)������ǰ�ߣ��Ϳ����������ˡ�\n");
			//me->delete_temp("ɽ��/�Ͷ���");
			me->set_temp("ɽ��/�߸���",1);
		}else
		{
			me->set_temp("giveletter",1);
			message_vision("$N���俴$nһ�ۣ���������һ�������أ�\n",this_object(),me);
		}
	}
	if (ob->query("name") == YEL"̴ľ��"NOR)
	{
		if (me->query_temp("giveletter"))
		{
			message_vision(
HIW"$N�򿪺��ӣ����˰��Σ����������´�����$nһ��������Ц��������Ȼ�Ǻ��ֵܣ�
�ðɣ�����ǰ�ߣ��и������£���ɽ�и��������µĵط������ĵĻ����Ǿ�����ȥ�ɣ���
���������ɽ�����Ϳ�Ե���ˡ�\n"NOR,this_object(),me);
			tell_object(me,"�ƿ����Ӻ������(open curtain)������ǰ�ߣ��Ϳ����������ˡ�\n");
			//me->delete_temp("ɽ��/�Ͷ���");
			me->set_temp("ɽ��/�߸���",1);
		}else
		{
			me->set_temp("givebox",1);
			message_vision("$N���俴$nһ�ۣ���������һ�������أ�\n",this_object(),me);
		}
	}
	return 1;
}





