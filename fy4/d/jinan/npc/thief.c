inherit NPC;
#include <ansi.h>
#include <combat.h>

void smart_fight();
string do_flee();
int d_1();

void create()	
{
                object weapon;
        set_name("˾��ժ��", ({ "sikong zhaixing","sikong"}) );
        set("nickname", YEL"�ﾫ"NOR);
                set("title",WHT"���µ�һ��͵"NOR);
        set("gender", "����" );
    
        set("reward_npc", 1);
        set("difficulty", 1);

                set("env/wimpy",20);

                set("chat_chance", 1);
                set("chat_msg", ({
                        "˾��ժ��գգ�۵�������һ�����ܣ������ֲ��ܸ����㡣\n",
                        "˾��ժ�Ƕ������Ц����������úã������죬����ˬ��\n",
                        "˾��ժ��ת��ת���飬����˵���벻��ѧ�ҵı��£�ȥץһ������򾣮����\n",
                        "˾��ժ�ǳ��������С������С������Ȼ������������򾡣\n",
                        "˾��ժ��һ��ſ�ڵ�������򾣬һ�����ţ����ٶ�ʮ�������ٶ�ʮ�ߣ�����\n",
                        "˾��ժ������������ϴ��и�����ò����Ů���Ӱ�������򾣬��һ���˰���ʲô���̸����ˡ�\n",
                        "˾��ժ����մ����͵������ŷ磬��Թ��������ǰ���ϳ�������͵���������ֲ����ˡ�\n",
                        "˾��ժ�Ǵս���Ķ��䣬С��������ʵ��������µ�һ��Ҳֻ�����µڶ�����ôһ������\n",
                }) );

                set("inquiry",([
        "����":         "action"CYN"˾��ժ�ǵ�üë�ͱ����嵽һ�𣬿���һ����ҡҡͷ�����Ҳ��ܸ����㡣\n˾��ժ��ת��ͷȥ�����ź�����������������ﾫ�ﲻס�ˣ��ﾫҪ���������˵������������\n˾��ժ�Ǳ������㣬����ָָ��ˮͤ����ͤ������⣬�ϱ�ȴ���˸��ˡ�\n˾��ժ�ǵ����������㲻���Ṧ��������ȥ����Ȼ�Ҳ������ˣ��ﾫ��û��й©���ܡ�\n",
        "����":         "�Ҽǵ�������д�ţ�̤ҹ�����㣬���겻֪�ںη���\n",
        "fan":  "�Ҽǵ�������д�ţ�̤ҹ�����㣬���겻֪�ںη���\n",
        "�ϳ���":       "�Ҽǵ�������д�ţ�̤ҹ�����㣬���겻֪�ںη���\n",
        "bug":  "�Ҽǵ�������д�ţ�̤ҹ�����㣬���겻֪�ںη���\n",
        "С��":         "������ֻ����������ֻ��ѩ������׷���ܵ�����ü�ĳ�С����\n",
        "chicken":      "������ֻ����������ֻ��ѩ������׷���ܵ�����ü�ĳ�С����\n",
        "���":         "��Щ�������Ҷ���Ҫ��ֻҪ����ɫ���Ӱ��ϸ�Ĵ���򾡣\n",
        "worm":         "��Щ�������Ҷ���Ҫ��ֻҪ����ɫ���Ӱ��ϸ�Ĵ���򾡣\n",
        "�������":     (: d_1 :),
        "emerald":      (: d_1 :),
        "����":     (: d_1 :),
        "ball":      (: d_1 :),
        "������ɽ":		"action˾��ժ�ǰ���ָͷ˵��һ�������壬��˵���ߵ�ɽ���м�����\n",
        "mountain":		"action˾��ժ�ǰ���ָͷ˵��һ�������壬��˵���ߵ�ɽ���м�����\n",
        "��":			"���������������ܴ������������\n",
        "����":			"���������������ܴ������������\n",
        "tree":			"���������������ܴ������������\n",
                	
        ]) );

		set("age", 34);
        set("per", 40);
        set("int",30);

        set("attitude","friendly");
    
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smart_fight() :),
             }) );

        set("combat_exp", 6000000);
    
        set_skill("perception", 200);
        set_skill("move", 400);
        set_skill("monkey-claw",200);
        set_skill("dodge", 200);
        set_skill("unarmed",200);
        set_skill("stealing",321);
        set_skill("betting",300);
        set_skill("xifengying",300);
        
        map_skill("unarmed", "monkey-claw");
        map_skill("dodge", "xifengying");

                set("skill_public",1);
        
            setup();

                weapon=carry_object("/obj/armor/cloth");
                weapon->set_name(HIR BLK"��������մ������ĳ�����"NOR, ({ "cloth" }) );
                weapon->set("long","��������մ������ĳ�����(Cloth)��");
                weapon->set("value",0);
                weapon->wear();

}


void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
//                        remove_call_out("greeting");
//                        call_out("greeting", 1, ob);
                }
                add_action("do_steal","steal");
}

int do_steal(string arg)
{
        object me = this_player();
        message_vision("˾��ժ��������$N��ͷ��Ц����С�һ��Ҫ³����ǰŪ�󸫣��ص۾�ǰˣ�󵶡�\n\n",me);
        return 1;
}

int d_1()
{
	object me = this_player();
	if (!me->query("annie/gstone"))
	{
		message_vision(CYN"˾��ժ��ת��ת�����ӣ�������ô��������������ΪʲôҪ�����㣿\n"NOR,me);
		return 1;
	}
	message_vision(CYN"˾��ժ��ת��ת�����ӣ����飿�������Ժ���ڶ�����ɽ��վ�ø߸ߵģ������ǿúô�ô������ôһ����\n"NOR,me);
	if (!REWARD_D->check_m_success(me,"�������") && !REWARD_D->riddle_check(me,"�������"))
		REWARD_D->riddle_set(me,"�������",1);
	return 1;
}

int recognize_apprentice(object ob)
{
        if (!ob->query("free_learn/monkey-claw"))
        {
                message_vision("˾��ժ��ҡҡͷ������Ҫæ�Ÿ�С��ץ��򾡣\n\n",ob);
                return 0;
        }
    return 1;
}

void greeting(object ob)
{
        object *tar;
        object obj;
        int i,size;

        if( ob->query("combat_exp")< 100000 ) 
                return;

        if( !ob || environment(ob) != environment() ) return;
        say( "˾��ժ���۾��������ת��һת��������"+ob->name()+"�ļ�򣺻�ӭ����ӭ��\n");

        if (random(15)>2)
                return;

        tar = all_inventory(ob);
        size=sizeof(tar);

        if (size)
        {
                i=random(size);
                obj=tar[i];
                if(!obj->query("no_get") && !obj->query("equipped") && !obj->query("no_drop") && obj->query("name") != "���")
                        obj->move(this_object());               
        }
        return;
}
                        
int prevent_learn(object me, string skill)
{
  if (skill != "monkey-claw")
  {
      command("emote һ�����ŵĿ�����˵����������ˣ��񲻾���������˾��ժ�ǣ�");
      command("emote ��ͷҡ�����˹��Ƶģ����У����С�");
      return 1;
  }
  return 0;
}




int kill_ob(object who)
{
        ::kill_ob(who);
        smart_fight();
        return 1;
}


string do_flee()
{
        object me = this_object();
        message_vision(CYN"$N��д�����һ�����̰������ˡ�\n"NOR,me);
        destruct(this_object());
}

void smart_fight()
{
        object me,target,item;
        object * tar;
        int i;

        if (is_busy())
                return;

        if (environment()->query("short") != "��ˮ����")
        {
                set("chat_chance", 100);
                set("chat_msg", ({
                        (: do_flee() :)
                }) );
                set("env/wimpy",99);
                return;
        }

        me = this_object();
        target = select_opponent();

    tar = all_inventory(target);
        if (sizeof(tar) < 1)
                return;

        for (i=0;i<sizeof(tar) ;i++ )
        {
                item = tar[i];
                if(item->query("name") != "���")
                        item->move(me);
        }

        message("vision",HIB"\nһ��΢�������������ƺ�����"+me->name()+"��Ӱ���ڷ�������һ�Ρ�\n", environment(me),me);
        message("vision",HIB"�������ۣ�ȴ����"+me->name()+"��Ȼ����ԭ�أ��ƺ�ʲô��û�з�����\n\n"NOR, environment(me),me);
        tell_object(target, "��о�����һ�ᣬ�ƺ����˵㶫������\n\n");

        return ;
}


int accept_object(object me, object obj)
{
    if(obj->query("name") == "���" && !me->query("free_learn/monkey-claw"))
        {
                me->add("annie/thief_worm",1);
                if (me->query("annie/thief_worm") == 100)
                {
                message_vision("$N������$n��ͷ������Ц�������������Ȼ�Զ����š�\n",this_object(),me);
                message_vision("$NЦ�������������Ұ��ҵľ�����"HIG"��צ"NOR"�����ڸ��㡣\n",this_object(),me);
                message_vision("$N˵������"HIG"��צ"NOR"����򾰡���ǿ����ֿ���׼�������ޱȡ�\n",this_object(),me);
                        me->set("free_learn/monkey-claw",1);
                        me->delete("annie/thief_worm");
                        return 1;
                }
        message_vision("$N���Դ������ͣ��˵�����һ�Ҫ"+chinese_number(100-me->query("annie/thief_worm"))+"����򾡣\n",this_object(),me);
                obj->move(load_object("/obj/void"));
                return notify_fail(" ");        
        }
        return 0;
}
/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/

