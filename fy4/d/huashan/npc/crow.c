#include <ansi.h>
inherit NPC;
mapping *way;
mapping *read_table(string file);
void create()
{
    set_name("������ѻ", ({ "crow" }) );
    set("race", "����");
    set("age", 1);
    set("gender", "����");
    set("long", "����ֻ����ߴߴ�����ĺ�����ѻ��\n");
    set("attitude","peaceful");
    
	set("weight", 200);
   
    	set("combat_exp", 800000);
		
	set_temp("apply/attack", 200);
	set_temp("apply/dodge",200);
	set_temp("apply/move",320);
	set_temp("apply/damage",50);
	set_temp("apply/armor", 50);
    
    set("chat_chance", 1);
    set("chat_msg", ({
    	"������ѻ�Թ�ұ�� ��~~��~ ��~~��~ ���� \n",
	}) );
    setup();
}
void init()
{
	::init();
	add_action("do_follow","follow");
}

void followme(object player)
{
	object room;
	room = find_object("/d/huashan/qipan");
	if (room != environment())
	{
		return;
	}
	if (player && environment(player) == environment())
	{
		message_vision("$N���˹�ұ���Ļ����˷ܵط�������������$n��ǰ���� 
�ƺ�Ҫ$n����ȥʲô�ط���\n",this_object(),player );
		player->set_temp("marks/ablefollowcrow",1);
		//add_action("do_follow","follow");
	}
}

void get_quest(string file)
{   
    way=read_table(file);
}
mapping *read_table(string file)
{
    string *line, *field, *format;
    mapping *data;
    int i, rn, fn;

    line = explode(read_file(file), "\n");
    data = ({});
    for(i=0; i<sizeof(line); i++) {
        if( line[i]=="" || line[i][0]=='#' ) continue;
        if( !pointerp(field) ) {
            field = explode( line[i], ":" );
            continue;
        }
        if( !pointerp(format) ) {
            format = explode( line[i], ":" );
            continue;
        }
        break;
    }

    for( rn = 0, fn = 0; i<sizeof(line); i++) {
        if( line[i]=="" || line[i][0]=='#' ) continue;
        if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
        sscanf( line[i], format[fn], data[rn][field[fn]] );
        fn = (++fn) % sizeof(field);
        if( !fn ) ++rn;
    }
    return data;
}
int arrive(object me)
{
	set("chat_chance", 1);
	set("chat_msg", ({"������ѻ�Թ�ұ�� ��~~��~ ��~~��~ ���� \n",}) );
	set("marks/in_follow",0);
	message_vision("�������$N�����˷ܣ��۵�һ���ɹ���ľ�� \n",this_object());
	if (objectp(me) && me->query_leader() == this_object())
	{
		me->set_leader(0);	
		me->set_temp("followcrow",1);
		message_vision("$N���Ÿ��Ϻ�����ѻ���������ܵĹ�ľ�ֵ�ס��$N��ȥ·��\n",me);
		message_vision("$N��̧ͷ��ʱ��������ѻ�Ѳ�����Ӱ��\n",me);
	}
	//should i destruct this object or move it back?
	destruct(this_object());
	return 1;
}
void go(object me)
{
	string		*dirc = ({ "��", "��", "��", "��" });
	int i,j,k;
	object room;
    string *cmds;
    remove_call_out("go");
    for(i=0;i<sizeof(way);i++)
    {
        if (base_name(environment()) != way[i]["room_file"]) continue;
        cmds=explode(way[i]["cmd_table"],";");
        break;
    }
    
    if (i>=sizeof(way))
    {   
        random_move();
        call_out("go",2,me);
        return;
    }
    for(j=0;j<sizeof(cmds);j++)
        command(cmds[j]);
    if (way[i]["delay_time"]<0)
    {
		//use move from here seems lame
		room = environment();
		k = random(3);
		message( "vision", this_object()->name() +  "��" + dirc[k] + "�뿪 ��\n", environment(this_object()), ({this_object()}) );
		this_object()->move("/d/huashan/duanshan");
		message( "vision", this_object()->name() + 
				(this_object()->is_naked() ? "��������" : "") 
				+  "���˹�����\n", environment(this_object()), ({this_object()}) );
		if (me && present(me,room))
		{
			message( "vision", me->name() + "��" + dirc[k] + "�뿪 ��\n", environment(me), ({me}) );
			me->move("/d/huashan/duanshan");
			message( "vision", me->name() + 
				(me->is_naked() ? "��������" : "") 
				+ "���˹�����\n", environment(me), ({me}) );
		}
		arrive(me);
        return;
	}
    call_out("go",way[i]["delay_time"],me);
    return;
}
int do_follow(string arg)
{
	object player;
	player = this_player();
	if (arg !="crow" && arg!="������ѻ")
	{
		return 0;
	}
	if (!player->query_temp("marks/ablefollowcrow"))
	{
		tell_object(player,"������ѻ���������㡣����\n");
		return 1;
	}
	if (query("marks/in_follow"))
	{
		tell_object(player,"������ѻ�������ڸ����˴�·�ء����� \n");
		return 1;
	}
	set("chat_chance", 10);
	set("chat_msg", ({"������ѻ�˷ܵ������ų�򣬷���ǰ�档 \n",}) );
	player->set_leader(this_object());
	set("marks/in_follow",1);
	player->delete_temp("marks/ablefollowcrow");
	get_quest(__DIR__"crowway");
    call_out("go",2,player);
}
int return_home(object home)
{
        //if crow is in action, don't make it return home
        if (query("marks/in_follow"))
        {
                return 1;
        }
        ::return_home(home);

}
