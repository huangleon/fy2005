// Silencer@fy4 workgroup

// �������ã�����

// �����������㡢�������㣬����

// ���ػ����ļ��ܡ��鼮



inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIW"���ܷ��䷿��"NOR);
	set("long", @LONG
��������������������ѧ���ļ������㣬ͬʱ�����˶���ߵ����Ե㣬
Ϊ�˼���������ѧϰ�ĸ�����һ���ֿ��Զ����Ļ������ܽ���ϵͳ�Զ��ṩ��
LONG
	);
	set("exits", ([
	]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",700);
	set("no_magic",1);
	set("no_fight",1);
	set("valid_startroom", 1);
	setup();
}

int init(){
	object me;
	string *att = ({"int","cps","agi","str","con","kar"});
	string *att_c = ({ "����","����","�ٶ�","����","����","����" });
	int i;
	mapping data;
	string *item;
	
	// ���·������Ե�
	me = this_player();
	if (me->query("id") != "tester")	return 1;
	
	tell_object(me,"==========================================\n");
	for (i=0;i<sizeof(att);i++){
		tell_object(me,"���ѧϰ�������"+ me->query("improve/"+ att[i])+ "��"+ att_c[i]+"\n");		
//		me->add(att[0],-me->query("improve/"+att[i]));
	}
	
	tell_object(me,"\n�ⲿ�����Ե�����ӻָ�����ʼֵ��\n\n");
	tell_object(me,"==========================================\n");


	// ����Ǳ�ܵ�	
	tell_object(me,"������ȥ��"+ me->query("learned_points")+"��Ǳ���Ѿ���ȫ�����أ�
����Ǳ��"+ me->query("potential")+"�㡣\n");
	tell_object(me,"==========================================\n");

//	me->delete("annie/skill_cost");
//	me->delete("learned_points");
	
	// �� ENable	
//	me->reset_skill_map();
	
	// �弼��
//	me->reset_skill();
		
	// ��learned	
//	me->reset_learned();
		
	me->save();

	// ���ü���

	return 1;
		
}

int improve_player(object me)
{
	// ����
	me->set_skill("literate",60);
	me->add("improve/int",2);
	me->add("int",2);

}

