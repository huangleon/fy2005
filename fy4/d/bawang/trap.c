#include <ansi.h>
inherit ROOM;

void create()
{
	object me;
	me = this_player();
	set("short", "�ݾ�");

	set("long", @LONG
����һ������ĺ�«�͵��ݾ������ڳ�ʪ���ֹ⻬��������Ϊ������ű���
�����Ѿ����õ�ʬ�壬���ܻ�ɢ���Ų��ٻư�֮���Ȼ�Ƕ���ɽ�ϵ�ǿ����ʱ��
ʱ�ھ��ڷ���Ľ�����Ա��ƺ����м�ֻ���������ںڰ��п������㣬�·��ڵ�
�Ž�����Ϊ��һ�����͡�
LONG);
	set("type","street");
	set("no_magic",1);
	set("outdoors","bawang");
	setup();
}

void init()
{	
	object me;
	add_action("do_climb", "climb");
	if( interactive( me = this_player()))
	{
		remove_call_out("sinking");
		call_out("sinking", 1, me);
	}
}

int sinking(object me)
{
	tell_object(me,RED"\n�˱ǵĶ���͵�ӿ����ı�ǻ�����ʱ�е�һ����Ϣ......\n\n�����������ת����ʶ����ģ����������ϡ��������������޵����Ц��......\n\n"NOR);
	message_vision("$N����һ�����Ļ赹�ڵ��ϡ�\n", me);
	me->unconcious();
	return 0;
}

int do_climb(string arg)
{
    object obj, me;
    int	kar;
    
    if(!arg || arg=="") return notify_fail("��Ҫ����������\n");
    me = this_player();
    if( arg == "wall" || arg == "����" || arg == "up")
    {
        if( me->is_busy() )
            return notify_fail("��Ķ�����û����ɣ������ƶ���\n");
        message_vision("$Nʹ�����̵�������˳�ž���������ȥ��\n", me);
        me->start_busy(1);
        call_out("climb_wall", 2, me);
        return 1;
    }
    return notify_fail("�㲻������"+arg+"��\n");
}       

int climb_wall(object me)
{
    int kar;
    
    if (me->is_ghost()) return 0;
    kar = (int)me->query("kar");
    if( kar > 60 ) kar = 60;
    if( random(60 - kar) < 15 )
    {
        me->move(__DIR__"shanlu2.c");
        message_vision("$N�������г��������˳�����\n", me);
    }
    else message_vision("$N����һ��ûץ�ȣ��ֵ���������\n", me);
    return 1;
}