inherit NPC;
#include <ansi.h>
void create()
{
        set_name("����", ({ "xu ning","sing girl","silencer" }) );
        set("gender", "����" );
        set("age", 31);
        set("title", CYN"��԰�߽�֮"NOR);
        set("nickname", WHT"���䶫��Ⱦ����"NOR);
        set("combat_exp", 150000);
        set("attitude", "friendly");
        set("per",30);
        set_skill("unarmed",150);
        set_skill("dodge",150);
        set_skill("parry",150);
        setup();
        carry_object(__DIR__"obj/fycloth")->wear();
}

void do_ggyy(int count)
{
        object me;
        string msg;
		object room;
        string *event_msg = ({
CYN"ֻ���ú�Ļ����̨��ת�������ɡ�\n"NOR,
CYN"��һ�ᣬһ��ɫ��ȹ�İ����������峪��\n"NOR,

WHT"\n��ȴ�˶��ҵ����ϣ�\n"NOR,
WHT"�����侹���������ĺ�ɽ!\n"NOR,
WHT"��һ��̨ͤ��ӳ�ڲ������棬\n"NOR,
WHT"��һ�Ժ�¥̨��������̶��\n"NOR,
WHT"�յ�������˿�Ѵ������죬\n"NOR,
WHT"������������Ӵ�����\n"NOR,

CYN"\n���������һ�٣�����ɤ�ӽ��ų�����\n"NOR,
WHT"��Ȼ�ǽж����ź����ϣ�\n"NOR,
WHT"��ͤ�Ϲ���������������\n"NOR,
WHT"����Ⱥú�ɽ��ü��չ��\n"NOR,
WHT"Ҳ�����¶�������һ����\n"NOR,

WHT"\nһɲʱ��ɫ�����ư���\n"NOR,
WHT"��һ�������������˰���\n"NOR,
WHT"�����ǧ����΢�β�����\n"NOR,
WHT"ȴΪ�ν����ﶸ����?\n"NOR,

CYN"\n������ת��һ�����¹��ӣ����г�������ɡ��\n"NOR,
CYN"������ִɡǰ��̽��������������峪��\n"NOR,
MAG"�ʲ�ɨĹ����ȥ��\n"NOR,
MAG"������������롣\n"NOR,
MAG"��æ�����������⣬\n"NOR,
MAG"���±���������?\n"NOR,

WHT"\n��������ɽ��ϴ������ϰϰ͸���¡�\n"NOR,
MAG"\n���������������ӣ���ױŨĨ�����ˡ�\n"NOR,
WHT"\n���ɾ����ںη�ס�����յ���ߵл���� \n"NOR,

MAG"\n����ס���岨���⣬Ǯ������С������\n"NOR,
MAG"ЩС֮�º�����⣬��������ֺ�ú�΢��\n"NOR,

WHT"\n������ϳ�����ϲ���д����ʰ�ͷ�͡�\n"NOR,
WHT"�����ȥ˵��ϸ�����ɾ���Ͼ�òܴʡ�\n"NOR,

WHT"\n��л����˼��㣬�������ҵ�Ǯ����\n"NOR,
WHT"�Ҽ�ס�ں�¥�ϣ����������罵�⡣\n"NOR,
WHT"������ҰѺ����ϣ�\n"NOR,
WHT"Ī����������ˮ����᳦��\n"NOR,

CYN"\n���������С����֣�����ת��̨��\n"NOR,
CYN"���ɿ��Ű�������ʧ�ķ������Ƭ���ֳ���\n"NOR,

MAG"\nһ�����ɹ����ϡ����������ɻ��ơ�\n"NOR,
MAG"��һ��С����������˫����ԧ�˺��к��\n"NOR,

CYN"\n��Ļ�������£��˽�ȥ��һ�ڡ�������ɡ����\n"NOR,
});
        me = this_object();
        msg = event_msg[count];
//        message_vision(msg,me);
		room = find_object("/d/fy/theater");
		if (!room)
			room = load_object("/d/fy/theater");
		tell_room(room,msg);
        if (count < sizeof(event_msg)-1)
                call_out("do_ggyy",1+random(2),count+1);
        return;

}



