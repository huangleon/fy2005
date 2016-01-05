#include <ansi.h>
inherit __DIR__"no_killing_place";
void create()
{
    set("short", "��ƺ");
    set("long", @LONG
����һƬ���̵Ĳ�ƺ������ȥ�����쳣�������º񣬲�ƺһֱ���쵽С���ϣ�
����ݸ�Ҳ�����ˮ֮�С������ϵ��˸�𣬲������ᵴ������ƺ�����棬һ�ø�
�����ͩ����֦��б�죬�������ٴִ����һ����ǧ��
LONG
        );
    	set("exits", ([
		"west" : __DIR__"livingroom",
	]) );

    	set("item_desc", ([
        "qiuqian":"��ǧϵ�ù�����ͣ���Ȼ��ª��ȴ������Ȥ����������ŵ���������������磩\n",
        "qiu qian":"��ǧϵ�ù�����ͣ���Ȼ��ª��ȴ������Ȥ����������ŵ���������������磩\n",
        "��ǧ":"��ǧϵ�ù�����ͣ���Ȼ��ª��ȴ������Ȥ����������ŵ���������������磩\n",
        "tree":"�ߴ����ͩ���Ѳ�ƺ�ı����ڵ�����ʵʵ��\n",
        "��ͩ��":"�ߴ����ͩ���Ѳ�ƺ�ı����ڵ�����ʵʵ��\n",
	]) );

	set("no_magic", 1);
    	set("outdoors","taoyuan");
	set("coor/x",30);
	set("coor/y",30);
	set("coor/z",0);
    	setup();
}

init()
{
	add_action("do_swing", "swing");
    	add_action("do_north", "go");
}

int do_north(string arg)
{
    	object room, me;
    	me = this_player();

	if (arg == "north") {
    		tell_object(me, "���ƹ���ͩ���������ݴԣ�����ط��������Ȼ���ж��죮����\n\n");
    		room=find_object(__DIR__"shuhou");
    		if(!objectp(room)) room=load_object(__DIR__"shuhou");
    		me->move(room);
    		return 1;
    	}
}

int do_swing(string arg)
{
    object me;

    me = this_player();

    	if(!arg || arg != "��ǧ" && arg != "qiu qian" && arg !="qiuqian" )
        	return 0;
    	switch (random (4))
    {
	    case 0:
	        message_vision(HIG"$N������ǧ�ϣ������ؿ�ʼ������ǧ��Խ��Խ�ߡ�\n"NOR,
	                       me);
	        break;
	    case 1:
	        message_vision(HIG"��ǧԽ��Խ�ߣ�$N���ɵý���ץס���١�\n"NOR, me);
	        tell_object(me, "��ֻ���÷�ӽŵ��ӹ������ƺ�Ҫ�˷��ȥ��\n");
	        break;
	    case 2:
	        message_vision(HIG"��ǧԽ��Խ�ߣ�$N���ɵý���ץס���١�\n"NOR, me);
	        message("vision", me->name()+
	                "�ƺ�������ʲô�������Ҵҵش���ǧ������������\n",
	                environment(me), me);
	        tell_object(me,"���Ȼ�����ж������鷿�ڷ���ҫ�۵Ĺ⣬��һ����ʧ��\n");
	        me->set_temp("marks/marble", 1);
	        break;
	    case 3:
	        message_vision(HIR"��ǧԽ��Խ�ߣ�$Nһ���������ǧ�ϵ���������\n"NOR,
	                       me);
	        tell_object(me, "���飡�������ص�ˤ�������ϣ�ƨƨ��ʹŶ�� \n");
	        me->receive_damage("gin",10);
	        me->receive_damage("kee",10);
	        me->receive_damage("sen",10);
	        me->set_temp("last_damage_from","����ǧˤ���ˡ�\n");
	        break;
    }
    return 1;
}
