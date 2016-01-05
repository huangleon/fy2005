//anniew.

#include <ansi.h>
inherit ROOM;
void warning(object me);
void capture(object me);
void create()
{
        set("short", "��԰");
        set("long", @LONG
ת���ɻ�������ɫٿȻһ�䣬��ɫ���ԣ���ѻ�ӹ���С·�ϻĲ�û����������
Ҳ�����˿�Ҷ����ͷ�Ŀ�ľ����С¥һ�ǣ���ϡ���ǵ���С��̽������ѧ��������
С�������ȴ���ѻķϣ�����������������
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  		"southwest" : __DIR__"hehuadang2",
	]));
        set("outdoors","qianjin");

        set("coor/x",-20);
        set("coor/y",10);
        set("coor/z",0);
        setup();
        
}

void init()
{
        object me = this_player();
        object room;
        add_action("do_search","search");
        
        remove_call_out("warning");
        remove_call_out("capture");
        if (	me->query("age") >13 
        	&& !NATURE_D->is_day_time()
                && me->query("age") <26 
                && !me->query_temp("afei_on_the_way")
                && me->query("combat_exp")>300000 
                && me->query("gender") == "Ů��" 
		) 
        {
                room = find_object(__DIR__"basement");
                if (!objectp(room)) room = load_object(__DIR__"basement");
                if (present("meihua dao",room))
                if (!objectp(room->query("occupied")))       // ÿ��ֻץһ��
                	call_out("warning", 10, me);
        }
        
}

void warning(object me) {
        if (environment(me) == this_object() ) {
        tell_object(me, WHT"\n��԰�ﺮѻ��������Ҷ������һ��Σ�յ�Ԥ��������÷ǳ�������\n\n"NOR);
                call_out("capture", 5, me);
        }
        
}

void capture(object me) {
        object room;
        if (environment(me) == this_object() ) {

        	message_vision(HIB"
��ľ���к�Ȼ����һ������ķ磬���쬵��������Ϲι������������ۣ�
ͻȻ�����ƺ��и���Ӱվ��$N�����$N�Ȼһ��������ת��ȴ�ѱ�
������Ѩ����


��Ӱ��$NЮ�����£����Ƽ��������˳�ȥ������\n\n"NOR, me);
                room=find_object(AREA_QIANJIN"basement");
                if(!objectp(room))
                        room=load_object(AREA_QIANJIN"basement");
                room->set("occupied",me);
                room->reset();
                me->set_temp("marks/meihuadao", 1);
                me->move(room);         
             	message_vision(HIR"
÷������$N�����˵����ҽ������С���ϣ�һ��Ī����״����ζϮ����
$N��Ϣһ�ϣ����˹�ȥ��\n"NOR,me);
             	me->unconcious();
        }
}

int do_search() {
        object me = this_player();
	object room;
	
	room = find_object(__DIR__"basement");
	if (objectp(room))
        if (me->query_temp("afei_on_the_way") && objectp(room->query("occupied")) ) {
                tell_object(me, WHT"\n��԰�ﺮѻ��������Ҷ������һ��Σ�յ�Ԥ��������÷ǳ�������\n\n"NOR);
                message_vision("$N������Ҷ�����ֵ�����һ�����ڡ�\n", me);
                if( !query("exits/down") ) {
                        set("exits/down", __DIR__"basement");
                        call_out("close_path", 2);                
                        
                }
                return 1;
        }
        me->delete_temp("afei_on_the_way");// Room Player probably quitted. Need restart.Or need ask afei
        tell_object(me,"��ʲôҲû���֣��ңУ���ʾ���㲻�����Ƕ�����ʲô�¶���û����\n");
        return 1;
}


void close_path()
{
        if( !query("exits/down") ) return;
        message("vision",
"һ��紵��ƬƬ��Ҷ���׷���������£��ڱ��˵��ϵĶ��ڡ�\n",
                this_object() );
                delete("exits/down");
}


void wine_notify(object who)
{
        object deer;

        deer = present("li huai", this_object());
        if(!objectp(deer))
        {
                deer = new(__DIR__"npc/lihuai");
                deer->move(this_object());
                message_vision(CYN"
һ���糾���͵������ˣ���һ������˵����ѣ�����������˳�����
������һ����$N���еľƺ�«������Ϳ�ʼ������
������$N˵��������Ц�ŵ���һ���ǹ��������������ģ����а��ص���Ϣ��ô��\n\n"NOR,who);
                REWARD_D->riddle_set(who,"������Թ",9);
         //     who->set("annie/riddle/moonmaster",9);
        }
}


/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/

