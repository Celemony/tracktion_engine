/*
    ,--.                     ,--.     ,--.  ,--.
  ,-'  '-.,--.--.,--,--.,---.|  |,-.,-'  '-.`--' ,---. ,--,--,      Copyright 2018
  '-.  .-'|  .--' ,-.  | .--'|     /'-.  .-',--.| .-. ||      \   Tracktion Software
    |  |  |  |  \ '-'  \ `--.|  \  \  |  |  |  |' '-' '|  ||  |       Corporation
    `---' `--'   `--`--'`---'`--'`--' `---' `--' `---' `--''--'    www.tracktion.com

    Tracktion Engine uses a GPL/commercial licence - see LICENCE.md for details.
*/

namespace tracktion_engine
{

//==============================================================================
/**
*/
class ArrangerClip  : public Clip
{
public:
    ArrangerClip (const juce::ValueTree&, EditItemID, ClipTrack& targetTrack);
    ~ArrangerClip();

    using Ptr = juce::ReferenceCountedObjectPtr<ArrangerClip>;

    bool isSyncAbsolute() const noexcept                            { return syncType == syncAbsolute; }
    bool isSyncBarsBeats() const noexcept                           { return syncType == syncBarsBeats; }

    juce::String getSelectableDescription() override;
    bool canGoOnTrack (Track&) override;
    juce::Colour getDefaultColour() const override;
    void initialise() override;

    bool isMidi() const override                                    { return false; }
    bool isMuted() const override                                   { return false; }

    AudioNode* createAudioNode (const CreateAudioNodeParams&) override      { return {}; }

protected:
    void valueTreePropertyChanged (juce::ValueTree&, const juce::Identifier&) override;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ArrangerClip)
};

} // namespace tracktion_engine
