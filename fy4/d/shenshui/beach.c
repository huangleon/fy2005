#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ɳ̲");
        set("long", @LONG
����һ����ɫ��ɳ̲�������ɳ̲�������µ���״��ϸ���ɳ��ɢ��������
ɫ�Ĺ���������������Ĵ��Ű��ߣ���ͷ���º�����ɳ̲��������ͷ׵ı��ǣ���
�Ǵ��͸�ɳ̲����������ɽ������ʵľ��ˣ���ǰ�ĺ����ﲼ���˺�ɫ�ľ�
ʯ�������Ȼ�ķ����̣����˴������潦�����ɫ���˻���
LONG
        );
       set("exits", ([
                "east" : AREA_TIEFLAG"rock0",
        ]));

    set("outdoors","shenshui");
    set("no_magic",1);
	set("coor/x",1780);
	set("coor/y",-12550);
	set("coor/z",20);
    setup();
}

void init()
{
	object me;

	if(interactive(me=this_player()))
	{
		remove_call_out("event_tide");
		call_out("event_tide",30,me,0);
	}
}

string* msg= ({
	HIY"����֮���� ��ʯ����� ����΢���� �����İ���
��ĿԶ���� �����������գ���ϼ���졣 \n\n"NOR,
	HIY"Ϧ��ȽȽ�뺣�����������ں����ϡ���������𲨣���ҫ���ѣ������ޱȡ� \n\n"NOR,
	WHT"ɳ���ϣ�Ÿ�ط�����ɳ���Ӱ������ƹ���Զ��
ż������������ƮƮ���ã�Զ�����⡣ \n\n"NOR,
	RED"ˮ�콻��֮����ĺ��������Ⱦ��ǧ���̲���硣 \n\n"NOR,
	HIW"�̺�����֮�У���������һҶ�������׷�һ�ơ���������Ƕ�ں���֮�ϣ�
ˮ��֮�䡣 \n\n"NOR,
	HIR"���ս���������Զ����䣬�������ϡ��������죬
��Զ��������ʱ�����������ף����춯�ء� \n\n"NOR,
	HIM"��Ŀ��ȥ�����ϲ���ɽ����������ӿ��һ�������򺣰����۶����� ����
���ס�˲�伴�����Ļ�������������ʯ���ƣ������Ѱ����������ذ�ɫ��
ˮ�����ѩ���ں��������������ӡ� \n\n"NOR,
});



void event_tide(object me,int count)
{
	if(!me||!living(me)||!present(me,this_object()))
		return ;
	if(count==sizeof(msg))
	{
		me->set("����B/����_����",1+random(10));
		return ;
	}
	message_vision(msg[count],me);
	call_out("event_tide",5,me,++count);
	return ;
}

/*
void do_flush(object me)
{
   object room;

    if(!me || environment(me) != this_object()) {
        return;
    }
    tell_object(me,"\nͻȻһ�����˰�����˳�ȥ��\n\n");
    if(random(2) > 1) {
        room = find_object(__DIR__"ocean1");
        if(!objectp(room)) room= load_object(__DIR__"ocean1");
        me->move(room);
    } else {
        room = find_object(__DIR__"beach");
        if(!objectp(room)) room = load_object(__DIR__"beach");
        me->move(room);
    }
}
*/

