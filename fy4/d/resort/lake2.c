inherit ROOM;
#include <ansi.h>

int do_look(string arg);
void create()

{
        set("short", "��ķ�����");
        set("long", @LONG
��������ʥ��֮һ����ķ�������������Զ��һ�����£�һ��ӵ����ԭ��һ
������ѩɽ��������ˮ���������Ĺ⣬һ���˵ؾ��򰶱ߣ��Ծ�����ɳ����������
�������ѣ�����ת���������������Ը�������ߵĽ�ʯ��Ҳ���š������������衱
���������ԡ�
LONG
        );
        set("exits", ([ 
		"southwest":  __DIR__"garden",
		]));
        set("objects", ([
        	__DIR__"npc/horse2":	1,
		]) );
		
		set("item_desc",	([
			
		]));	
		
		set("outdoors", "guanwai");
        set("coor/x",60);
        set("coor/y",0);
        set("coor/z",10);
		setup();

}

void init(){
		add_action("do_look","look");
}



int 	do_look(string arg){
		object room, me = this_player();
		int duration, mark;
							
		if (arg != "lake" && arg != "��" && arg != "����" && arg!= "��ˮ")	return 0;
			
		if (REWARD_D->riddle_check(me,"��ͯת��") == 999)
		{
			duration = me->query("timer/lingtong") + 3600 - time();
			if (duration>0)
			{
				tell_object(me,"������Ժ���һ����ѣ���޷����������ۺ���\n");
				tell_object(me,"����ȴ�"+ chinese_number(duration/60) + "���ӣ�\n");
				return 1;
			}
			REWARD_D->riddle_set(me,"��ͯת��", 4);
			me->delete("timer/lingtong");
		}
				
		if (REWARD_D->riddle_check(me,"��ͯת��") != 4)
		{
			tell_object(me,"��ķ�����ˮ�������������ԣ�ǳ�úܣ�����ɽ�ϻ�ѩ�ڻ���ע��İɡ�\n");
			return 1;
		}
		
		if (me->is_busy())
		{
			tell_object(me,"��������æ���޷����������ۺ���\n");
			return 1;
		}
			
		tell_object(me, YEL"����㡢���ơ���Ŀ�����Ȼ���������ȥ��\n"NOR);
		me->start_busy(1);
		
		if (query("kids_out") || random(5))	
		{
			tell_object(me,"��ˮ������ӳ�Ű���Ⱥ���ĵ�Ӱ������۾������ˣ�����û�п���ʲô��\n");		
			return 1;
		}
		
		tell_object(me,HIG"\n�������ƣ�ˮ��������������������Զ�������������Գ�����ɽɫ��\n"NOR);

tell_object(me,CYN"


        __   ,:`-_    /\   /\            ,d@@b,
     ,-'W;`./WI;:.`-./W;.\/;.\_          @@@@@@
   ,'WWI;::.\ W;:' /WWWI;.`--'.\         `?@@P'
  /WWI;;;:. .`.W' /WWWII;:..:;:.`-.__
<= Mystery is the key to enchantment `=>--------------------------
  \  ~     -  '   \  ~ _      ~  -'      _~-~~   _   ~        ~
   `    ~   /  ~   \       ~-  /   ~     ~-_~-~        -  ~      ~
 ~   `-.   '\     .- \ ~ /\  /~          -~_ ~-
        ~~   `.,-~    \/   \/    -    ~  ~

"NOR);
		
		me->start_busy(30);
		
		mark = random(10);
		call_out("do_riding",2,me, mark,  0);
		
/*		for (i=0;i<sizeof(area);i++) {
			room = load_object("/d/"+area[i]);
			if (!room)	write("error = " + area[i]+"\n");
		}*/
		
			
				
		set("kids_out",1);
		call_out("kid_off",1200, me, 0); 	
		return 1;
	
}

string view(string room) {
	int i;
	object *inv,env;
	mapping exits;
	string roomdesc, str, *dirs;
	
	env = find_object(room);
	if (!env) env = load_object(room);

	str = CYN"\n\nˮ���ζ���գ�ۼ��ֻ���һ������\n\n"NOR;
	
	// room descriptions.
	str += sprintf( "%s \n%s",
			env->query("long"),
	// exits.
			env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

	// all things in the room.
	inv = all_inventory(env);
	for(i=0; i<sizeof(inv); i++) {
		if( inv[i]->query("no_shown") ) {
			continue;
		}
		str += "  " + inv[i]->short() + "\n";
	}
	return str;
}


void do_riding(object me,int mark, int count)
{
	object room, kid;
	int i, num;
	string msg;
	string *area = ({ 	"baiyun/skystreet3","biancheng/road2","chenxiang/cxcenter",
						"eren/groad4","fugui/xiaojie3","fy/fysquare",
						"huangshan/wenquan","huashan/hpath2","jinan/street3",
						"laowu/street","loulan/saintpalace","qianfo/road1",
						"qingping/road2","resort/front_yard",	"songshan/shuyuan",
						"taiping/mroad5","taishan/luohan","taoguan/road1",
						"xinjiang/bazha3","biancheng/grassland4", "bat/renjiandao2",
						"changchun/moonding", "chuenyu/sunnyroad","fycycle/road3",
						"wudang/wuroad4", "wanmei/cleft","baiyun/hillroad",
					});
		
		
	if (!me || environment(me)!= this_object())
		return;
		
	if (count < 10 )
	{
		kid = new("/obj/npc/lamakid");
		kid ->set("starter", me);
		num = random(sizeof(area));
		if (!(room = find_object("/d/"+area[num])))
			room = load_object("/d/"+area[num]);			
		
		if (count == mark) {
			kid->set("lama_owner", me);
			set("real_room","/d/"+area[num]);
		}
		
		if (!kid->move(room))
			destruct(kid);
//		write(" number " + count + "\n");
		message_vision(view("/d/"+area[num]),me);
		count ++;
		call_out("do_riding",2,me, mark, count);
	}
	else
	{
		message_vision(HIG"\n\nˮ����ƽ��һ���ָֻ���ԭ�����ྲ��\n\n"NOR, me);
		me->stop_busy();
		msg = "��������"+ NATURE_D->game_time()+ "��ʼ̽�ð���ת����ͯ��";
		CHANNEL_D->do_sys_channel("info", msg);
		return;
	}
}


int kid_off(object me, int flag) {
    object *ob_list;
    int i;
    string msg;
    set("kids_out",0);
    
    ob_list = children("/obj/npc/lamakid");
	for(i=0; i<sizeof(ob_list); i++) {
    	if(environment(ob_list[i])) {
        	message_vision(CYN"$N˫�ƺ�ʮ������ȥ�ˣ�\n"NOR,ob_list[i]);
        	ob_list[i]->move(VOID_OB);
        }
        destruct(ob_list[i]);    
    }
    if (!flag) {
		msg = "������̽�ð���ת����ͯ��ʱ���أ�δ�����ա�";
		REWARD_D->riddle_set(me,"��ͯת��", 999);	// failed
		me->set("timer/lingtong", time());	
	}
	else
		msg = "�����¼������ۣ�����" + NATURE_D->game_time()+ "��ð���ת����ͯ��";
		
	CHANNEL_D->do_sys_channel("info", msg);    
}

int ending(object me, int flag) {
	
	string msg;
	remove_call_out("kid_off");
	call_out("kid_off", 2, me, flag);
	return 1;
}
