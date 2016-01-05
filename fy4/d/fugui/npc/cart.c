#include <ansi.h>
inherit ITEM;
object owner;

void to_rob(object me);
void check(object ob,object me);
mapping default_dirs = ([
        "north":        "����",
        "south":        "����",
        "east":         "����",
        "west":         "����",
        "northup":      "����",
        "southup":      "�ϱ�",
        "eastup":       "����",
        "westup":       "����",
        "northdown":    "����",
        "southdown":    "�ϱ�",
        "eastdown":     "����",
        "westdown":     "����",
        "northeast":    "����",
        "northwest":    "����",
        "southeast":    "����",
        "southwest":    "����",
        "up":           "����",
        "down":         "����",
        "enter":        "����",
        "out":          "����",
]);

void create()
{
        set_name("�ڳ�", ({ "silver cart", "cart"}) );
        set_weight(300000);
        set("no_get", 1);
        set("no_clean_up",1);
        set_max_encumbrance(80000000);
	set("unit", "��");
	set("long", "һ����������ڳ���������Ž��˧���ı�־��\n����ԣ�drive cart to <����>����Ѻ���ڳ�ǰ����\n");
	set("closed", 1);
	set("value", 2000);
}

void init()
{
	::init_item();
	add_action("do_open","open");
	add_action("do_close","close");
	add_action("do_drive","drive");
	call_out("destroy",random(900)+900,this_object());
}

int is_container() {return 1;}

int do_close(string arg)
{
	object me,ob;
	me = this_player();
	ob = this_object();
        if(arg != "cart" && arg != "silver cart")
                return notify_fail("��Ҫ����ʲô��\n");
        if(ob->query("closed"))
        	return notify_fail("�ڳ��Ѿ��ǹ��ŵ��ˡ�\n");
       	message_vision("$N��$n�Ź����ˡ�\n", me, ob);
	ob->set("closed",1);
	return 1;
}

int do_open(string arg)
{
	object me,ob;
	me = this_player();
	ob = this_object();
	if(arg != "cart" && arg != "silver cart")
    		return notify_fail("��Ҫ��ʲô��\n");
        if(!ob->query("closed"))
        	return notify_fail("�ڳ��Ѿ��ǿ��ŵ��ˡ�\n");
	message_vision("$N��$n�Ǵ򿪡�\n", me, ob);
  	ob->set("closed",0);
        return 1;
}

int do_drive(string arg)
{        
        object me,ob, env, obj;
        string item, dir, dest, target;
        mapping exit;
        me = this_player();
        ob = this_object();

        if(!arg) return notify_fail("��ҪѺ��ʲô��\n");
        
        if(me != owner)
        	return notify_fail("�㲻���ڳ������ˣ�\n");

        if( sscanf(arg, "%s to %s", item, dir) != 2 ||
                item != "cart" && item != "silver cart")
                return command(query_verb()+" "+arg);
                        
        if( me->is_busy() )
                return notify_fail("��������æ������\n");

        if ( present("robber",environment(this_player())))
                return notify_fail(HIR"�ٷ�����һ�����������ܣ�û��ô���ף���\n"NOR);
        
        if ( present("theif leader",environment(this_player())))
                return notify_fail(HIR"�㻹���Ȱ�ë���������˵��\n"NOR);
        
        if ( this_player()->is_fighting())
                return notify_fail("�㻹���ȰѶ��ֽ������˵�ɣ�\n");
 
        env = environment(me);
        if(!env) return notify_fail("��Ҫȥ���\n");
        
        if( !mapp(exit = env->query("exits")) || undefinedp(exit[dir]) ) 
        {
                if( query_verb()=="drive")
                        return notify_fail("����������ȥ��\n");
                else
                        return 0;
        }
        
        dest = exit[dir];
                        
        if( !(obj = find_object(dest)) )
                call_other(dest, "???");
        if( !(obj = find_object(dest)) )
                return notify_fail("û��������Ѻ�ˡ�\n");

        if( !undefinedp(default_dirs[dir]) )
                target = default_dirs[dir];
        else
                target = obj->query("short");

        message_vision("\n$N�����ڳ���" + target + "ʻȥ��\n",me);
        message_vision("�ڳ�¡¡��"+ target + "ʻȥ��\n",me);

        if( ob->move(obj) && me->move(obj)) 
        {
		all_inventory(env)->follow_me(me, dir);
		message_vision("$N�����ڳ�ʻ�˹�����\n",me);
		message_vision("�ڳ�¡¡ʻ�˹�����\n",me); 
		me->start_busy(random(3));
        }
        check(ob,me);
	to_rob(me);
        return 1;
}

void check(object ob, object me)
{
        object room;
        string placename;
        room = environment(ob);
        placename = (string) room->query("short");
        if (placename ==(string)me->query_temp("dart_area") 
             && present(me->query_temp("dart_id"), environment(me)) )
           {  
              message_vision(HIY"$N���˸����������ڰ����˵��˵�ͷ��\n\n"NOR,me);
              message_vision(HIY+me->query_temp("dart_name")+
                "�ɻ�Ķ�$N˵������"+RANK_D->query_respect(this_player())
                +"�����ˣ������Һͽ��˧���޽��飬\n����«������ʲôҩ����\n\n"NOR,me);
              me->start_busy(2);
              me->delete_temp("dart_area");
              me->delete_temp("dart_id");
              destruct(ob);
              return;
            }  
}

void destroy(object ob)
{
	message_vision(HIR"ͻȻ���Ӵ��һ�������������ڳ����ˡ�\n"NOR,ob);
	destruct(ob);
	return;
}

void set_owner(object player)
{	
	owner=player;
}

void to_rob(object me)
{
	object robber,room;
	int i,exp, chance;
	room = environment(this_player());
	me= this_player();
	exp = (int) me->query("combat_exp");
	if (exp >1200000)
		exp = 1200000;
	if( environment(this_player())->query("no_fight") ) return;
	
	if (!this_object()) return;
	
	if( !me->query_temp("meet_poor") && environment(this_object())->query("bandit_out"))
	{
		me->set_temp("meet_poor",1);
		chance=sizeof(me->query("����B"))+sizeof(me->query("����A"));
		chance = 3+chance/2;
		chance = random(chance);
		if (chance) return;
		message_vision(HIY"ͻȻ�������������ڵĽٷ˴Ӱ������˳�������е������������Ӱ������˾ͻش壡����\n\n"NOR,this_player()); 
		
		for (i=0;i<2;i++)
		{
			robber=new(__DIR__"poorrobber");
			robber->move(room);
			robber->set("combat_exp",100000 + random(100000));
			robber->set_leader(me);
		}
		robber=new(__DIR__"robleader");
		robber->move(room);
		robber->set("combat_exp",200000 + random(100000));
		robber->fight_ob(me);
		me->fight_ob(robber);
		robber->set_leader(me);
	}
	
	if (environment(this_object())->query("bandit_out")) me->set_temp("meet_poor",1);
	
	if (!random(8))
	{
		message_vision(HIR"ͻȻ�������ٷ˴Ӱ������˳�������Ц�����������������������ɣ�����\n\n"NOR,this_player()); 
		for (i=0;i<=random(5)+1;i++)
		{
			robber=new(__DIR__"robber");
			robber->move(room);
			robber->set("combat_exp",exp + random(100000));
			robber->kill_ob(me);
			me->kill_ob(robber);
			robber->set_leader(me);
		}
	}
	me->start_busy(2);
	return;
}
