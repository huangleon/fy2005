// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", "���㺣");
    set("long", @LONG
��������Ϊ�����ѵõĹȵأ�������ǻ�ʢ�ţ�����������ϰϰ�����ɷ�
������䣬����ڤڤ����ľ�������뿪�˿��ﵥ���Ļ����ֲ��������ǰ��
�̵Ļ�ľ��������������������÷�Ȼ�ɾ���ֱ����ƽ�����׻���֮�䣬����
Ƭ�̵�������
LONG
NOR
        );
	set("objects", ([
		__DIR__"obj/pine":1,
		__DIR__"obj/hole":1,
	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"westup" : "path7",
  		"eastup" : "path8",
  		"southup" : "forest5",
	]) );

	set("outdoors", "cyan");
	set("area","cyan3");

	set("coor/x",-40);
	set("coor/y",50);
	set("coor/z",70);
	setup();
}

void trigger(object me)
{
	object ob;
	message_vision(CYN"ԭ��һ����Цٻ���������Ů������������������\n",me);
	message_vision(MAG"(�㶢����Ů����ϵĴ���̺ۣ�һʱ������ʮ�����ƣ�������ԨԴ�������ȴ�벻����������)\n\n",me);
	message_vision(CYN"�����������������Ц���ҵĴ���ү����������ˣ����Ѱ��Ѱ�ý�ͷ�ö�㵹�ǲ��������һ�ٱ�������\n",me);
	message_vision(CYN"����˵������̳����������������ء���������ˮϴһ������Ȼ���ǿ���ȥ�ɣ���ĪҪ�ϵ��������˼������źá�\n",me);
	message_vision(CYN"��������һ�����ƿ�����˸�����ƮȻ��ȥ��\n",me);

	tell_object(me,HIY"�������ı��ˣ�\n"NOR);

	me->set("quest/short", WHT"��"CYN+"ӳ������"+WHT"����ħ̳���³���"NOR);
	me->set("quest/location", "ӳ������");
	me->set("quest/duration",3600);
	me->set("quest/quest_type","special");
	me->set("quest_time",time());

	REWARD_D->riddle_set(me,"���Ļ���",1);


	if (present("su ruo"))
		destruct(present("su ruo"));

	return;
}


int	valid_leave(object who, string dir)
{
	object me;
	me = who;

	if (dir != "eastup")
		if (REWARD_D->riddle_check(me,"���Ļ���") == 1) 
			return notify_fail("������ȥ��ʦ���ɡ�\n");

	return ::valid_leave(who,dir);
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


